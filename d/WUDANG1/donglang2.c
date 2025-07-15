// Room: /d/shaolin/donglang2.c
// By Marz 04/01/96 

inherit ROOM;

void create()
{
    set("short", "东厢走廊");
    set("long", @LONG
你走在一条走廊上，隐约可以听到东边传来呼吸声，似乎有人正在那里练功，
南边是间竹子扎就的屋子，十分的素雅，里面飘出一阵阵的茶香，有人轻声细语
地不知说那些什么，引得女孩子＂吃吃＂笑出声来。
LONG
    );

    set("exits", ([
	"east" : __DIR__"liangongfang",
	"south" : __DIR__"chashi2",
	"west" : __DIR__"donglang1",
    ]));
                                                    
       setup();
    replace_program(ROOM);
}

