#include "playscene.h"
#include <QDebug>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include "mycoin.h"
#include <QPropertyAnimation>

PlayScene::PlayScene(int level)
{
    this->levelIndex = level;
    QString str = QString("进入了第%1关").arg(levelIndex);
    qDebug() << str;

    this->setFixedSize(320,588);
    this->setWindowIcon(QPixmap(":/res/Coin0001.png"));
    this->setWindowTitle(QString("第%1关").arg(levelIndex));

    //菜单栏
    QMenuBar *bar = menuBar();
    setMenuBar(bar);
    QMenu *startMenu = bar->addMenu("开始");
    QAction *quitAction = startMenu->addAction("退出");
    connect(quitAction,&QAction::triggered,this,[=](){
        this->close();
    });

    QSoundEffect *backSound = new QSoundEffect;
    backSound->setSource(QUrl::fromLocalFile(":/res/BackButtonSound.wav"));
    backSound->setLoopCount(1);
    QSoundEffect *winSound = new QSoundEffect;
    winSound->setSource(QUrl::fromLocalFile(":/res/LevelWinSound.wav"));
    winSound->setLoopCount(1);
    //返回按钮
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn,&MyPushButton::clicked,this,[=](){
        backSound->play();
        qDebug() << "clicked the button of back in the play!";
        QTimer::singleShot(100,this,[=](){
            emit this->chooseSceneBack();
        });
    });

    /////????必须提前初始化吗?????????????????
    QLabel *winLabel = new QLabel(this);
    QPixmap tempPix(":/res/LevelCompletedDialogBg.png");
    winLabel->setGeometry(0,0,tempPix.width(),tempPix.height());
    winLabel->setPixmap(tempPix);
    winLabel->move((this->width() - tempPix.width())*0.5, -tempPix.height());
    connect(this, &PlayScene::gameWin, this, [=](){
        qDebug() << "load picture!";
        winSound->play();
        setWinBackground(winLabel);
    });

    //初始化游戏信息
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            this->gameArray[i][j] = config.mData[this->levelIndex][i][j];
        }
    }

    setLevelIndex();
    setCoin();
}

void PlayScene::setWinBackground(QLabel *winLabel)
{
//    qDebug() << "load picture in function!";
//    QLabel * winLabel = new QLabel(this);
//    QPixmap tempPix(":/res/LevelCompletedDialogBg.png");
//    winLabel->setGeometry(0,0,tempPix.width(),tempPix.height());
//    winLabel->setPixmap(tempPix);
//    winLabel->move((this->width() - tempPix.width())*0.5, 0);
    QPropertyAnimation *animation = new QPropertyAnimation(winLabel, "geometry");
    animation->setDuration(1000);
    animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
    animation->setEndValue(QRect(winLabel->x(), winLabel->y()+114, winLabel->width(), winLabel->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void PlayScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //背景
    QPixmap pix(":res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":res/Title.png");
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}

bool PlayScene::judgeWin()
{
    this->isWin = true;
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            if(false == coinBtn[i][j]->flag){
                this->isWin = false;
                return this->isWin;
            }
        }
    }
    emit this->gameWin();
    qDebug()<<"Win!!!!!";
    return this->isWin;
}

void PlayScene::changeOtherCoin(MyCoin *coin)
{
    if(coin->posX + 1 <= 3){
        coinBtn[coin->posX + 1][coin->posY]->changeFlag();
        this->gameArray[coin->posX + 1][coin->posY] = !this->gameArray[coin->posX + 1][coin->posY];
    }
    if(coin->posX - 1 >= 0){
        coinBtn[coin->posX - 1][coin->posY]->changeFlag();
        this->gameArray[coin->posX - 1][coin->posY] = !this->gameArray[coin->posX - 1][coin->posY];
    }
    if(coin->posY - 1 >= 0){
        coinBtn[coin->posX][coin->posY - 1]->changeFlag();
        this->gameArray[coin->posX][coin->posY - 1] = !this->gameArray[coin->posX][coin->posY - 1];
    }
    if(coin->posY + 1 <= 3){
        coinBtn[coin->posX][coin->posY + 1]->changeFlag();
        this->gameArray[coin->posX][coin->posY + 1] = !this->gameArray[coin->posX][coin->posY + 1];
    }
}

void PlayScene::setLevelIndex()
{
    QLabel *label = new QLabel(this);
    label->setGeometry(30, this->height()-50,120,50);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    QString str_level = QString("Level:%1").arg(this->levelIndex);
    label->setFont(font);
    label->setText(str_level);
}

void PlayScene::setCoin()
{
    QSoundEffect *flipSound = new QSoundEffect;
    flipSound->setSource(QUrl::fromLocalFile(":/res/CoinFlipSound.wav"));
    flipSound->setLoopCount(1);
    for(int i = 0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            QPixmap pix(":res/BoardNode.png");
            QLabel *label = new QLabel(this);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->move(57 + i*50, 200 + j*50);
//            label->setStyleSheet("text-align:center;font-size:1px;");
            //设置父亲为label
            QString str;
            //设置正反面
            if(this->gameArray[i][j] == 1){
                str = ":/res/Coin0001.png";
            }
            else{
                str = ":/res/Coin0008.png";
            }
            MyCoin * coin = new MyCoin(str);
            coin->setParent(label);
            coin->move(1,2);
            coin->setInfo(i, j, gameArray[i][j]);
//            coin->move(58 + i*50, 202 + j*50);

            //游戏胜利信号
            connect(this, &PlayScene::gameWin, coin, &MyCoin::setWinFlag);

            coinBtn[i][j] = coin;
            connect(coin, &MyCoin::clicked, this, [=](){
                coin->changeFlag();
                flipSound->play();
                this->gameArray[i][j] = !this->gameArray[i][j];
                QTimer::singleShot(100,this,[=](){
                    changeOtherCoin(coin);
                    judgeWin();
                });
            });
        }
    }
}
