//changan city

inherit ROOM;
#include <ansi.h>

void create ()
{
//          set ("short",HIR "[" HIY "喜福会" HIR "]" NOR);
              set ("short", "喜福会大厅" );
        set ("long", @LONG

这儿是喜福会的厅堂，几桌客人在高兴的吃着东西，不时有猜拳行令的声
音传进你的耳朵，你惊奇的发现他们虽然谈笑风声，却感觉不到一般的酒
楼那种吵闹的气氛。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
		"south" : __DIR__"xifuhui1",
                  "north" : __DIR__"furong",
                  "east" : __DIR__"meigui",
                  "west" : __DIR__"mudan",
        "down" : __DIR__"chufang",
         ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/boss" : 1,
                  __DIR__"npc/guanshi" : 1,
        ]));


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


