// TIE@FY3 ALL RIGHTS RESERVED

#include <room.h>

inherit ROOM;

void create()

{

        set("short", "千佛殿");

        set("long", @LONG

又名昆卢阁，雕饰相当精致，明间悬额有“西方圣人”的竖匾，殿

前月台宽敞，石栏精美。殿正中的神龛里，供奉昆卢铜佛，坐于多层莲

花座上，殿东有白玉南无阿弥陀佛一尊，四周壁画精美，尤其引人注目

的是地上的四十八个凹陷的脚坑。

LONG

        );

        set("exits", ([ 

  "northdown" : __DIR__"neimen",

  "southdown" : __DIR__"lishi",

  "east" : __DIR__"baiyi",

  "west" : __DIR__"dizang",

]));

        set("objects", ([

                __DIR__"obj/footstep" : 1,

       ]) );

	set("coor/x",-210);

	set("coor/y",280);

	set("coor/z",70);

	setup();

	create_door("west", "木门", "east", DOOR_CLOSED);

}

