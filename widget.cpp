#include "widget.h"
#include "ui_widget.h"
#include<config.h>
#include<QIcon>
#include"mmap.h"
#include<QPainter>
#include<QMouseEvent>
#include<ctime>
#include<QSoundEffect>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);


    initscene();

    playgame();


}

Widget::~Widget()
{
    delete ui;
}

void Widget::initscene()
{


    setFixedSize(game_width,game_height);

    setWindowTitle(game_title);

    setWindowIcon(QIcon(game_icon));

    mtimer.setInterval(game_rate);
    srand((unsigned int)time(NULL));
    enemycount=0;

    m_explosionSound.setSource(QUrl(sound_path)); // 确认资源路径
    m_explosionSound.setVolume(4.0f);
}

void Widget::playgame()
{
    mtimer.start();
    connect(&mtimer,&QTimer::timeout,[=](){

        summonenemy();
        updatepostition();

        update();
        whetherdocollision();

    });

}

void Widget::updatepostition()
{
    map.mmapposition();
    myplane.shoot();

    for(int i=0;i<bullet_num;i++)
    {
        if(myplane.mybullet[i].m_free==false)
        {
            myplane.mybullet[i].updateposition();
        }


    }

    for(int i=0;i<enemy_num;i++)
    {


        if(enemys[i].m_free==false)
        {

            enemys[i].setposition();
        }
    }


    for(int i=0;i<bomb_num;i++)
    {

        if(bombs[i].m_free==false)
        {

            bombs[i].updateinfo();

        }


    }

}

void Widget::paintEvent(QPaintEvent *)
{

    QPainter painter(this);

    painter.drawPixmap(0,map.mmap1_postition,map.mmap1);
    painter.drawPixmap(0,map.mmap2_postition,map.mmap2);
    painter.drawPixmap(myplane.m_x,myplane.m_y,myplane.m_plane);
    for(int i=0;i<bullet_num;i++)
    {
        if(myplane.mybullet[i].m_free==false)
        {
             painter.drawPixmap(myplane.mybullet[i].m_x,myplane.mybullet[i].m_y,myplane.mybullet[i].m_bullet);
        }


    }

    for(int i=0;i<enemy_num;i++)
    {


        if(enemys[i].m_free==false)
        {

            painter.drawPixmap(enemys[i].m_x,enemys[i].m_y,enemys[i].enemy1);}
    }
    for(int i=0;i<bomb_num;i++)
    {

        if(bombs[i].m_free==false)
        {

            painter.drawPixmap(bombs[i].m_x,bombs[i].m_y,bombs[i].m_pixarr[bombs[i].m_index]);

        }


    }

}

void Widget::mouseMoveEvent(QMouseEvent *event)
{
    int x1=event->x()-0.5*myplane.m_rect.width();
    int y1=event->y()-0.5*myplane.m_rect.height();
    if(x1<=0)
    {

        x1=0;

    }
    if(x1>=game_width-myplane.m_rect.width())
    {



        x1=game_width-myplane.m_rect.width();


    }


    if(y1<=0)
    {

        y1=0;

    }
    if(y1>=game_height-myplane.m_rect.height())
    {



        y1=game_height-myplane.m_rect.height();


    }



    myplane.setpostion(x1,y1);



}

void Widget::summonenemy()
{

    enemycount++;
    if(enemycount<=enemyinterval)
    {

        return;
    }
    enemycount =0;
    for(int i=0;i<enemy_num;i++)
    {
        if(enemys[i].m_free)
        {

            enemys[i].m_free=false;
            enemys[i].m_x=rand()%(game_width-enemys[i].m_rect.width());
            enemys[i].m_y=-enemys[i].m_rect.height();
                break;
        }


    }
}

void Widget::whetherdocollision()
{

    for(int i=0;i<enemy_num;i++)
    {
        if(enemys[i].m_free)
        {
            continue;
        }


        for(int j=0;j<bullet_num;j++)
        {

            if(myplane.mybullet[j].m_free)
            {
                continue;
            }

            if(enemys[i].m_rect.intersects(myplane.mybullet[j].m_rect))
            {

                myplane.mybullet[j].m_free=true;

                enemys[i].m_free=true;


                for(int k=0;k<bomb_num;k++)
                {

                    if(bombs[k].m_free)
                    {

                        m_explosionSound.play();
                        bombs[k].m_free=false;
                        bombs[k].m_x=enemys[i].m_x+0.5*(enemys[i].enemy1.width());
                        bombs[k].m_y=enemys[i].m_y+0.5*(enemys[i].enemy1.height());
                        break;
                    }


                }



            }




        }

    }






}
















