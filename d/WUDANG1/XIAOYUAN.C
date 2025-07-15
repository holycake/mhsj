// xiaoyuan.c 
// netill /98/8/14/

#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short",HIC "小屋" NOR);
	set("long", @LONG
一间小屋，布置简简单单，除了一床、一桌、一椅、一蒲团，再也
没有别的什物。比较引人注目的是墙上挂着一把剑。这里就是武当开山
祖师张三丰的练功所在,张三丰常许多绝世武功都是在此悟出来的。
LONG
	);

	set("exits", ([
		"south" : __DIR__"tianzhu",
	]));
		set("objects", ([ /* sizeof() == 1 */
                              __DIR__"npc/zhangsanfeng" : 1,
	]));
	create_door("south", "竹门", "north", DOOR_CLOSED);
	setup();
	replace_program(ROOM);
}

