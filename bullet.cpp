#include "bullet.h"
#include "config.h"




bullet::bullet() {

    m_bullet.load(bullet_path);
    m_x=0;
    m_y=0;
    speed=bullet_speed;
    m_free = true;
    m_rect.setWidth(m_bullet.width());
    m_rect.setHeight(m_bullet.height());
    m_rect.moveTo(m_x,m_y);




}

void bullet::updateposition()
{
    if(m_free)
    {
        return ;
    }

    m_y-=speed;
    m_rect.moveTo(m_x,m_y);


    if(m_y<=-m_rect.height())
    {

        m_free=true;

    }


}
