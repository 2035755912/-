#ifndef ENEMYPLANE_H
#define ENEMYPLANE_H
#include "config.h"
#include <QPixmap>
#include<QRect>
class enemyplane
{
public:
    enemyplane();

    QPixmap enemy1;

    int m_x;
    int m_y;
    int speed;
    bool m_free;
    QRect m_rect;
    void setposition();







};

#endif // ENEMYPLANE_H
