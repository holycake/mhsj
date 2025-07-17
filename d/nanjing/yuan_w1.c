#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
这里是花园的西边，青条石铺就的小径两旁长满了竹子，地上种着兰花和蕨类植物
。不时有风将竹林吹得沙沙作响。
LONG
        );
        set("exits", ([
		"north" : __DIR__"yuan_nw",
		"south" : __DIR__"yuan_w2",
		"east" : __DIR__"yuan_rockery",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
