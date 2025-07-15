// /d/wudang/tianzhu/
// netkill /98/8/14/

#include <room.h>
inherit ROOM;

void create()
{
	set("short", "天柱峰");
	set("long", @LONG
这里是武当的最高峰，天柱峰，放眼看去，只见云海茫茫，清风拂面
你已忘却了人间烦恼，只觉得飘飘欲仙，好似要飞了出去。北面似乎有间
小室。
LONG
	);

	set("exits", ([
		"north" : __DIR__"xiaoyuan",
		"southdown" : __DIR__"chaotian",
	]));
	create_door("north", "竹门", "south", DOOR_CLOSED);
	setup();
	
}

