// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "藏经楼");
        set("long", @LONG
专研天下正派武功，各大名门正派的武功这里均有记载，几名老僧
正在苦修，据传每人兼通数艺，即便是那一派掌门，也未必有此功力，
想博览这里的书籍，只有得到几位老僧的垂青。
LONG
        );
        set("exits", ([ 
  "up" : __DIR__"cj4",
  "down": __DIR__"cj2",
]));
        set("objects", ([
                __DIR__"npc/monk20c" : 3,
       ]) );
	set("coor/x",-210);
	set("coor/y",360);
	set("coor/z",90);
	setup();
	create_door("up", "木门", "down", DOOR_CLOSED);

}
