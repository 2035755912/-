#include "heroplane.h"
#include "config.h"
heroplane::heroplane() {

    //ini
    m_plane.load(hero_path);

    m_x =0.5*(game_width-m_plane.width());
    m_y = game_height-m_plane.height();

    m_rect.setWidth(m_plane.width());
    m_rect.setHeight(m_plane.height());
    m_rect.moveTo(m_x,m_y);
    recorder = 0;


}

void heroplane::shoot()
{

    if(recorder++<=intervall)
    {
        return;
    }

    recorder =0;



    for(int i=0;i<bullet_num;i++)
    {
        if(mybullet[i].m_free)
        {

            mybullet[i].m_free=false;
            mybullet[i].m_x=m_x+0.5*m_rect.width();
            mybullet[i].m_y=m_y;
            break;
        }



    }


}

void heroplane::setpostion(int x, int y)
{
    m_x=x;
    m_y=y;
    m_rect.moveTo(m_x,m_y);




}
