#include "mainscene.h"
#include "./ui_mainscene.h"



MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);

    //设置窗口固定大小
    this->setFixedSize(320,588);
    //设置背景图标
    this->setWindowIcon(QIcon(":/res/Coin0001.png"));
    this->setWindowTitle("翻金币");
    connect(ui->actionQuit, &QAction::triggered, this, [=](){
        this->close();
    });

    //按钮处理
    QSoundEffect *startSound = new QSoundEffect;
    startSound->setSource(QUrl::fromLocalFile(":/res/TapButtonSound.wav"));
    startSound->setLoopCount(1);
    startBtn = new MyPushButton(":res/MenuSceneStartButton.png");
//    startBtn->installEventFilter(this);
    startBtn->setParent(this);
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    chooseScene = new ChooseLevelScene;
    chooseScene->setAttribute(Qt::WA_DeleteOnClose);
    //关卡场景
    connect(startBtn,&QPushButton::pressed,this,[=](){
        startSound->play();
        startBtn->zoomDown();
    });
    //监听关卡场景的返回信息
    connect(chooseScene,&ChooseLevelScene::chooseSceneBack,this,[=](){
        this->setGeometry(chooseScene->geometry());
        chooseScene->hide();
        this->show();
    });
    connect(startBtn,&QPushButton::released,this,[=](){
        startBtn->zoomUp();
//        qDebug() << "release!";

        ////////////???????全局捕获
        //延时进入关卡
        QTimer::singleShot(100,this,[=]{
            //设置场景位置
            chooseScene->setGeometry(this->geometry());
            this->hide();
            chooseScene->show();
        });
    });


}

MainScene::~MainScene()
{
    delete ui;
}

void MainScene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    //设置背景
    pix.load(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //设置背景标题
    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix);
}

//bool MainScene::eventFilter(QObject *watched, QEvent *event)
//{
//    if(watched == startBtn){
//        if(QEvent::MouseButtonRelease == event->type()){
//            startBtn->zoomUp();
//            qDebug() << "event filter!";
//            return false;
//        }
//    }
//    return QMainWindow::eventFilter(watched,event);
//}

