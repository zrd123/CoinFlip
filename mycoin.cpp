#include "mycoin.h"
#include <QDebug>

MyCoin::MyCoin(QString btnImage)
{
    timer1 = new QTimer(this);
    timer2 = new QTimer(this);

    setPixmap(btnImage);

    connect(timer1, &QTimer::timeout,this,[=](){
        QString str = QString(":/res/Coin000%1.png").arg(min++);
        setPixmap(str);
        if(this->min > this->max){
            this->min = 1;
            isAnimation = false;
            timer1->stop();
        }
    });
    connect(timer2, &QTimer::timeout,this,[=](){
        QString str = QString(":/res/Coin000%1.png").arg(max--);
        setPixmap(str);
        if(this->min > this->max){
            this->max = 8;
            isAnimation = false;
            timer2->stop();
        }
    });
}

void MyCoin::setInfo(int x, int y, bool flag)
{
    this->posX = x;
    this->posY = y;
    this->flag = flag;
}

void MyCoin::changeFlag()
{
    //if(!isAnimation){
        if(this->flag){
            timer1->start(30);
            isAnimation = true;
            this->flag = false;
        }
        else{
            timer2->start(30);
            isAnimation = true;
            this->flag = true;
        }
        //}
}

void MyCoin::setWinFlag()
{
    this->isWin = true;
}

void MyCoin::mousePressEvent(QMouseEvent *e)
{
    if(this->isAnimation || this->isWin){
        return ;
    }
    else{
        QPushButton::mousePressEvent(e);
    }
}

void MyCoin::setPixmap(QString path)
{
    QPixmap pix;
    bool ret = pix.load(path);
    if(!ret){
        QString str = QString("图片 %1 加载失败!").arg(path);
        qDebug() << str;
        return;
    }
//    qDebug()<< "set coin icon";
    this->setFixedSize(pix.width(),pix.height());
    this->setStyleSheet("QPushButton{border:0px;}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(), pix.height()));
}
