#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QEvent>
#include <QDebug>
#include <QParallelAnimationGroup>
#include <QPropertyAnimation>
#include <QTimer>


class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    MyPushButton(QString normalImage, QString pressImage = "");

    void zoomUp();
    void zoomDown();

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);

    void loadPixmap(QString path);

//    bool event(QEvent *e){
//        if(QEvent::MouseButtonRelease == e->type()){
//            this->zoomUp();
//            qDebug() << "event filter!";
//            return false;
//        }
//        return QPushButton::event(e);
//    }
private:
    QString normalImagePath;
    QString pressImagePath;

signals:

};

#endif // MYPUSHBUTTON_H
