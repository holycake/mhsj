// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
大雄殿通往六祖殿的捷径，红木为栏，琉璃做顶，曲折回绕，妙不
可言，扶手之上雕花切字，两边廊壁之上尽是题字题诗，历代僧人多有
把禅机写于此间者。这里墙上一首特别引人注目。相传为神秀所书“身
是普提树，心如明镜台，时时勤拂拭，莫遣有尘埃。”
LONG
        );
        set("exits", ([ 
  "eastup" : __DIR__"daxiong",
  "west" : __DIR__"liuzu2",
]));
	set("coor/x",-220);
	set("coor/y",210);
	set("coor/z",40);
	setup();
        create_door("west", "木门", "east", DOOR_CLOSED);

}
