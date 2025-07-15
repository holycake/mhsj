// TIE@FY3 ALL RIGHTS RESERVED
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "六祖殿");
        set("long", @LONG
与紧那罗殿东西相对，殿面阔三间，殿内祀初祖达摩，二祖慧可，三祖
僧粲，四祖道信，五祖弘忍，六祖慧能塑像，正中供奉观音菩萨，称为
“六祖朝观音”，四周墙壁还画有历代名僧画像。确是佛家宝殿。
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"liuzu",
]));
        set("objects", ([
                __DIR__"npc/xin_qian" : 1,
       ]) );
	set("coor/x",-230);
	set("coor/y",210);
	set("coor/z",40);
	setup();
        create_door("east", "木门", "west", DOOR_CLOSED);

}
