#include "chooselevelscene.h"

ChooseLevelScene::ChooseLevelScene(QWidget *parent)
    : QMainWindow{parent}
{
    this->setFixedSize(310,588);
    this->setWindowIcon(QPixmap(":res/Coin0001.png"));
    this->setWindowTitle("选择关卡场景");

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
    //回退按钮信息
    MyPushButton *backBtn = new MyPushButton(":/res/BackButton.png", ":/res/BackButtonSelected.png");
    backBtn->setParent(this);
    backBtn->move(this->width() - backBtn->width(), this->height() - backBtn->height());
    connect(backBtn,&MyPushButton::clicked,this,[=](){
//        qDebug() << "clicked the button of back!";
        backSound->play();
        QTimer::singleShot(100,this,[=](){
            emit this->chooseSceneBack();
        });
    });

    setLevel();

}

void ChooseLevelScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    //背景
    QPixmap pix(":res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //标题
    pix.load(":res/Title.png");
    painter.drawPixmap((this->width()-pix.width())*0.5, 30, pix.width(), pix.height(), pix);
}

void ChooseLevelScene::setLevel()
{
    QSoundEffect *chooseSound = new QSoundEffect;
    chooseSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    chooseSound->setLoopCount(1);
    for(int i = 0; i < 20; ++i){
        MyPushButton *menuBtn = new MyPushButton(":/res/LevelIcon.png");
        menuBtn->setParent(this);
        menuBtn->move(25 + i%4*70, 130 + i/4*70);
        //menuBtn->setText(QString::number(i));

        connect(menuBtn,&MyPushButton::clicked,this,[=](){
           QString str = QString("您选择的是第%1关").arg(i+1);
           qDebug() << str;
           chooseSound->play();
           //关卡场景
           play = new PlayScene(i+1);
           play->setGeometry(this->geometry());
           this->hide();
           play->show();

           connect(play, &PlayScene::chooseSceneBack, this, [=](){
               this->setGeometry(play->geometry());
               this->show();
               delete play;
               play = nullptr;
           });
        });

        //////////////??????图标缝隙显示空白/////////
        QLabel *label = new QLabel(this);
        label->setFixedSize(menuBtn->width(),menuBtn->height());
        label->setText(QString::number(i+1));
        label->move(25 + i%4*70, 130 + i/4*70);
        label->setAlignment(Qt::AlignCenter);
        //设计鼠标穿透
        label->setAttribute(Qt::WA_TransparentForMouseEvents);

    }
}
