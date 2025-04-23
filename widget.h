#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QIcon>
#include<QTimer>
#include<QPainter>
#include"mmap.h"
#include"heroplane.h"
#include"bullet.h"
#include"enemyplane.h"
#include"bomb.h"
#include<QSoundEffect>
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


    void initscene();// main scene func

    void playgame();


    void updatepostition();

    void paintEvent(QPaintEvent*);

    void mouseMoveEvent(QMouseEvent*);

    void summonenemy();

    void whetherdocollision();
    QTimer mtimer;
    mmap map;
    enemyplane enemys[enemy_num];
    heroplane myplane;
    bomb bombs[bomb_num];
    int enemycount;

    QSoundEffect m_explosionSound;


private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
