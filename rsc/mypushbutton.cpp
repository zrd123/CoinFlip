#include "mypushbutton.h"

MyPushButton::MyPushButton(QString normalImage, QString pressImage)
{
    this->normalImagePath = normalImage;
    this->pressImagePath = pressImage;

    loadPixmap(this->normalImagePath);
//    QPixmap pix;
//    if(!pix.load(normalImage)){
//        qDebug() << "图片加载失败!";
//        return;
//    }
//    //button size
//    this->setFixedSize(pix.width(),pix.height());
//    //image style
//    this->setStyleSheet("QPushButton{border:0px;}");
//    //set image
//    this->setIcon(pix);
//    //set image size
//    this->setIconSize(QSize(pix.width(),pix.height()));
//    qDebug() << "tupian";
}

void MyPushButton::loadPixmap(QString path)
{
    QPixmap pix;
    if(!pix.load(path)){
        qDebug() << "图片加载失败!";
        return;
    }
    //button size
    this->setFixedSize(pix.width(),pix.height());
    //image style
    this->setStyleSheet("QPushButton{border:0px;}");
    //set image
    this->setIcon(pix);
    //set image size
    this->setIconSize(QSize(pix.width(),pix.height()));
    //qDebug() << "tupian";
}

void MyPushButton::zoomUp()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));

    //move style
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::zoomDown()
{
    QPropertyAnimation* animation = new QPropertyAnimation(this, "geometry");
    animation->setDuration(100);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));

    //move style
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}

void MyPushButton::mousePressEvent(QMouseEvent *e)
{
    if(this->pressImagePath != ""){
        loadPixmap(this->pressImagePath);
    }
    return QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(this->normalImagePath != ""){
        loadPixmap(this->normalImagePath);
    }
    return QPushButton::mouseReleaseEvent(e);
//    this->zoomUp();
//    qDebug() << "event filter!";
}



//bool MyPushButton::event(QEvent *e)
//{
//    if(QEvent::MouseButtonRelease == e->type()){
//        this->zoomUp();
//        qDebug() << "event filter!";
//        return false;
//    }
//    return QPushButton::event(e);
//}


