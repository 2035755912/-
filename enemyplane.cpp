#include "enemyplane.h"
#include"config.h"
enemyplane::enemyplane() {


    enemy1.load(enemypath);
    m_x=0;
    m_y=0;
    m_free=true;
    m_rect.setWidth(enemy1.width());
    m_rect.setHeight(enemy1.height());
    m_rect.moveTo(m_x,m_y);
    speed = enemyspeed;



}

void enemyplane::setposition()
{

    if(m_free)
    {
        return;
    }

    m_y+=speed;
    m_rect.moveTo(m_x,m_y);
    if(m_y>=game_height+m_rect.height())
    {
        m_free=true;

    }



}
