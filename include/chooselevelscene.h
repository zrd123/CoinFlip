#ifndef CHOOSELEVELSCENE_H
#define CHOOSELEVELSCENE_H

#include <QMainWindow>
#include <QMenuBar>
#include <QPainter>
#include "mypushbutton.h"
#include <QLabel>
#include <QTimer>
#include "playscene.h"
#include <QSoundEffect>

class ChooseLevelScene : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseLevelScene(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    void setLevel();

signals:
    //告诉主场景要返回
    void chooseSceneBack();

private:
    PlayScene *play = nullptr;

};

#endif // CHOOSELEVELSCENE_H
