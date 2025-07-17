#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "花园");
        set("long", @LONG
花园的东北侧有几栋小楼，似乎是专门给女眷居住的地方。
LONG
        );
        set("exits", ([
		"south" : __DIR__"yuan_e1",
		"west" : __DIR__"yuan_n",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
        setup();
}
