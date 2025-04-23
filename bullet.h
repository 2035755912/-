#ifndef BULLET_H
#define BULLET_H
#include"config.h"
#include <QPixmap>
#include<QRect>
class bullet
{
public:
    bullet();

    void updateposition();

    QPixmap m_bullet;
    int speed;
    bool m_free;
    int m_x;
    int m_y;
    QRect m_rect;




};

#endif // BULLET_H
