//By waiwai@mszj 2000/10/26

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIB"【野郎中医馆】"NOR);
        set("long", 

"\n你现在正站在野郎中医馆里，到这里来的人都是需要变态的 \n"+
"门口站着一个收费的小二......地下竖着一块牌子 "+HIR"(paizi)\n\n"NOR

        );
	set("item_desc", ([
		"paizi": HIC"需要变态的 "+HIR"\"give 5000 gold to er\" \n\n"NOR,
	]));

        set("exits", ([
                "south" : "/d/changan/wside5",
               
         ]) );

        set("objects", ([
		__DIR__"npc/xiaoer" : 1,
        ]));

        set("no_kill", 1);
        set("no_bian", 1);

        setup();
}
