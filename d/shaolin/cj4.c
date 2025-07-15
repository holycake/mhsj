// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
专门研究天下邪派武功，尤其是毒，定力不强者往往会因为邪派武
功易于速成而修练，结果走上魔道，所以这层一般不允许轻易上来，更
别说研究邪派武功了，倒是几本解毒方面的书籍可以稍做研究。当然武
学之道，存乎一心，若内力惊人，定力深厚，那么研究邪派武功有益无
害。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj5",
  "down": __DIR__"cj3",
]));
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",100);
	setup();
	create_door("down", "木门", "up", DOOR_CLOSED);

}
void init()
{
	this_player()->apply_condition("unknown",
                (int)this_player()->query_condition("unknown")
                + random(3)+3);
}

