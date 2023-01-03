#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <QMainWindow>
#include <QLabel>
#include "dataconfig.h"
#include "mycoin.h"
#include <QSoundEffect>

class PlayScene : public QMainWindow
{
    Q_OBJECT
public:
    //explicit PlayScene(QWidget *parent = nullptr);
    explicit PlayScene(int level);
    void setWinBackground(QLabel *winLabel = nullptr);

    bool isWin = false;

protected:
    void paintEvent(QPaintEvent *event);

signals:
    void chooseSceneBack();
    void gameWin();

private:
    int levelIndex = 0;
    DataConfig config;
    int gameArray[4][4];
    MyCoin *coinBtn[4][4];

    bool judgeWin();
    void changeOtherCoin(MyCoin * coin);
    void setLevelIndex();
    void setCoin();

};

#endif // PLAYSCENE_H
