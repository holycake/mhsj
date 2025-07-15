// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "内院");
        set("long", @LONG
一个空旷的黄土院子。
LONG
        );
        set("exits", ([ 
  "northup" : __DIR__"jialan",
  "south" : __DIR__"neiyuan2",
]));
        set("outdoors", "shaolin");
	set("coor/x",-210);
	set("coor/y",320);
	set("coor/z",60);
	setup();
	create_door("northup", "木门", "southdown", DOOR_CLOSED);

}
