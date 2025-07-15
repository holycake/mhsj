// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "饭厅");
        set("long", @LONG
一间巨大的屋子，屋内四排长桌，上面放着各类蔬菜，食品，每天
晨钟暮鼓之后，僧人便在这里聚集，享用食物。一般按等级高低依次进
食，各桌菜肴不同，可见等级尊卑之严。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"neiyuan",
  "west" : __DIR__"qianzao",
]));
        set("objects", ([
                __DIR__"npc/monk9" : 1,
       ]) );
	set("coor/x",-220);
	set("coor/y",300);
	set("coor/z",60);
	setup();
	create_door("west", "木门", "east", DOOR_CLOSED);

}
