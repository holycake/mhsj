// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "长廊");
        set("long", @LONG
大雄殿下来，由这通向紧那罗殿，红木为栏，琉璃做顶，曲折回绕，
两边廊壁题字题诗甚多，六祖慧能答神秀书便在此地，特别引人注目，
正是那首“普提本非树，明镜亦非台，本来无一物，何处染尘埃？”
五祖弘忍见此诗后便把衣钵传与慧能，后神秀不服，慧能南遁，从此禅
宗分为南北二宗。东行便是紧那罗殿。
LONG
        );
        set("exits", ([ 
  "westup" : __DIR__"daxiong",
  "east" : __DIR__"jinna2",
]));
	set("coor/x",-200);
	set("coor/y",210);
	set("coor/z",40);
	setup();
        create_door("east", "木门", "west", DOOR_CLOSED);

}
