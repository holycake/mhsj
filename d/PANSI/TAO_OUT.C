#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "桃花迷阵");
        set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。远处偶尔传来一声鸟叫。往南是一片桃
花林，往北远方遥遥听见轰轰隆隆的水声,似乎有个瀑布。
LONG );
       set("exits", ([
           "south" : __DIR__"tao_in",
           "north" : __DIR__"pubu",
       ]));
       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
}
/*
void init()
{       object ob;
        mapping myfam;
        if( interactive( ob = this_player()))
        if(query("exits/south")) 
        if ((int)ob->query_skill("spells",1) > 100 )
        {
            delete("exits/south");
            set("exits/south", __DIR__"tao_in");
            return ;
        }
        myfam = (mapping)ob->query("family");
        if(myfam && myfam["family_name"] == "盘丝洞")
        {
            delete("exits/south");
            set("exits/south", __DIR__"tao_in");
            return ;
        }       
  	delete("exits/south");
        set("exits/south", __DIR__"tao0");
}
*/
