//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short","白虎大街");
        set ("long", @LONG

这里已是白虎大街的西段，北面小巷里隐约看到一座大的草堂，堂外
挂一蓝布幌子，上写一个“卦”字。南面巷中一行歪柳，处处民宅，
几个小同在巷中玩耍。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"beiyin1",
                "north" : __DIR__"caotang",
                "west" : __DIR__"ximen",
                "east" : __DIR__"baihu-w2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//                __DIR__"npc/libai" : 1,
        ]));


        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}

