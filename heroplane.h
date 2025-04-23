#ifndef HEROPLANE_H
#define HEROPLANE_H
#include<QPixmap>
#include<QRect>
#include"bullet.h"
class heroplane
{
public:

    heroplane();
    void shoot();
    void setpostion(int x,int y);

    int m_x;
    int m_y;

    QPixmap m_plane;
    QRect m_rect;
    bullet mybullet[bullet_num];
    int recorder;


};

#endif // HEROPLANE_H
