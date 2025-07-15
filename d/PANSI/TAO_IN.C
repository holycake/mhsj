//2001.2.2

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", "桃花迷阵");
        set("long",@LONG
这是一片桃花的海洋。四周一望无际，全是盛开的桃花。微风拂过，
落英缤纷。周围静悄悄的。东西边好像有个树丛。远处偶尔传来一声
鸟叫。往北是一片桃花林，往南远远看见几只猴子。
LONG );
       set("exits", ([
           "south" : "/d/dntg/hgs/houshan3",
           "north" : __DIR__"tao_out",
           "east" : __DIR__"taob",
           "west" : __DIR__"taoa",
       ]));
	   set("objects",([
		__DIR__"npc/xiang" : 1,
		__DIR__"obj/guo" : 3,
	]));


       set("outdoors","taohua");
       set("no_clean_up", 0);
       setup();
       replace_program(ROOM);
}
/*
void init()
{
        object ob;
        mapping myfam;
	ob = this_player() ;
        if(query("exits/north")) 
			 myfam = (mapping)ob->query("family");
			if(myfam && myfam["family_name"] == "盘丝洞")
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_out");
	return ;
        }       
        if ((int)ob->query_skill("spells",1) >= 100 )
        {
        delete("exits/north");
        set("exits/north", __DIR__"tao_out");
	return ;
        }
	delete("exits/north");
    set("exits/north", __DIR__"tao0");
}
*/
