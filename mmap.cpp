#include "mmap.h"
#include<config.h>
mmap::mmap() {

    mmap1.load( game_mmap);
    mmap2.load(game_mmap);
    mmap1_postition=0;
    mmap2_postition=-game_height;
    mmapspeed = map_speed;






}

void mmap::mmapposition()
{
    mmap1_postition+=mmapspeed;
     mmap2_postition+=mmapspeed;
    if(mmap1_postition>=game_height)
    {

        mmap1_postition=-game_height;


    }

    if(mmap2_postition>=game_height)
    {

        mmap2_postition=-game_height;


    }






}
