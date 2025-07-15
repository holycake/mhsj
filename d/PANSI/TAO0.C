#include <room.h>
#include <ansi.h>

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
		"east" :  __FILE__,
		"west" :  __FILE__,
		"south" : __FILE__,
		"north" : __FILE__,
       ]));
       set("no_clean_up", 0);
       setup();
}

/*void init()
{
    this_player()->receive_damage("kee", 10);
    this_player()->receive_wound("kee",  10);
	this_player()->receive_damage("sen", 10);
    this_player()->receive_wound("sen",  10);
    message_vision(HIM"突然一阵桃花瓣象雨点般疾射$N！\n"NOR, this_player());
}
*/
int valid_leave(object me, string dir)
{
        int total_steps;
        if( me->query_skill("spells",1) >100) total_steps = 1 ; 
           else total_steps = 10;
	if ( dir == "north")
            me->add_temp("taohua/steps",1);
	if ( dir == "south")
            me->add_temp("taohua/steps",-1);
	if (me->query_temp("taohua/steps") == total_steps)
        {
     	    me->move(__DIR__"tao_in");
            me->delete_temp("taohua/steps");
            return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
        } 
        if (me->query_temp("taohua/steps") == - total_steps )
        {  
            me->move(__DIR__"tao_out");
            me->delete_temp("taohua/steps");
            return notify_fail("你走了半天，终于走出了桃花迷阵。\n");
     	}
        return ::valid_leave(me,dir);
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
