#ifndef MYCOIN_H
#define MYCOIN_H

#include <QPushButton>
#include <QTimer>

class MyCoin : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyCoin(QWidget *parent = nullptr);
    explicit MyCoin(QString btnImage);

    void setInfo(int x, int y, bool flag);
    void changeFlag();

    void setWinFlag();

    int posX,posY;
    bool flag;  //正反面

signals:


protected:
    void mousePressEvent(QMouseEvent *e);

private:
    QTimer * timer1, *timer2;
    bool isAnimation = false;
    bool isWin = false;

    void setPixmap(QString path);


    int min = 1;
    int max = 8;
};

#endif // MYCOIN_H
