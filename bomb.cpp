#include "bomb.h"
#include"config.h"
bomb::bomb() {
    for(int i=1;i<=bomb_index_max;i++)
    {
        QString str= QString(bomb_path).arg(i);
        m_pixarr.push_back(QPixmap(str));
    }


    m_x=0;
    m_y=0;
    m_free= true;
    m_index=0;
    m_recorder=0;




}

void bomb::updateinfo()
{
    if(m_free)
    {
        return;
    }
    m_recorder++;
    if(m_recorder<bomb_interval)
    {
        return;
    }

    m_recorder=0;
    m_index++;

    if(m_index>bomb_index_max-1)
    {
        m_index=0;
        m_free=true;

    }







}
