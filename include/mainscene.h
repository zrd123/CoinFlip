#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>
#include "chooselevelscene.h"
#include "mypushbutton.h"
#include <QTimer>
#include <QIcon>
#include <QImage>
#include <QPushButton>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();


protected:
    void paintEvent(QPaintEvent *event);

//    bool eventFilter(QObject *watched, QEvent *event);


private:
    Ui::MainScene *ui;
    ChooseLevelScene *chooseScene = nullptr;
    MyPushButton *startBtn = nullptr;
    QSoundEffect *mainSound = nullptr;

};
#endif // MAINSCENE_H
