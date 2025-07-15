#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",MAG "紫霄宫" NOR);
	set("long", @LONG
	在你的面前是一座道观，上面写着“紫霄宫”三个朱红色的大字，由此
往内就是武当的庙产了，现在进香的人明显少了，而穿不同服色的道士确不断进
进出出，诵经的声音隐隐传来。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shibapan",
 		"northup" : __DIR__"shijie61",  
	]));
	set("objects", ([
"/d/wudang1/npc/ying" : 1,
]));
	setup();
	replace_program(ROOM);
}

