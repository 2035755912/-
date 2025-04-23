#ifndef CONFIG_H
#define CONFIG_H



//GAMES CONFIG DATA
#define game_width 480
#define game_height 700
#define game_title "plane_wars"
#define game_res_path "./plane.rcc"


#define game_icon ":/myres/app.png"   //图标
#define game_mmap ":/myres/background.png"  //背景
#define game_rate 10 //ms
#define map_speed 1


#define hero_path ":/myres/me2.png"        //己方飞机路径



#define bullet_path ":/myres/bullet5.png"  //子弹路径
#define bullet_speed 10
#define bullet_num 35
#define intervall 100 //bullet cool down



#define enemypath ":/myres/enemy2.png"   //敌人路径
#define enemyspeed 3
#define enemyinterval 50
#define  enemy_num 20



#define bomb_path ":/myres/bomb0%1.png"
#define bomb_num 20
#define bomb_index_max 5
#define bomb_interval 10


#define sound_path ":/myres/attack.wav"



#endif // CONFIG_H
