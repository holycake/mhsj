// Room: some place in 西牛贺洲
// gate.c
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "山门");
  set ("long", @LONG
[1;37m
门口立一石碑，约有三丈馀高，八尺馀阔，上有一行十个大字，
乃是[2;37;0m
      [1;35m※※※※※※※※※                         ※※※※※※※※
      [1;35m※ 　 　 ※                         ※      ※
　    ※　　   ※                         ※      ※
      ※  [1;37m 斜[1;35m  ※    [1;33m何   本   明   菩[1;35m    ※[1;37m  灵[1;35m  ※
      ※       ※　                       ※  　  ※
      ※  [1;37m 月[1;35m  ※　  [1;33m处   来   镜   提[1;35m    ※[1;37m  台[1;35m  ※
      ※       ※　                       ※　  　※
      ※[1;37m   三[1;35m  ※    [1;33m惹   无   亦   本[1;35m    ※[1;37m  方[1;35m  ※
      ※       ※                         ※　    ※
      ※[1;37m   星[1;35m  ※    [1;33m尘   一   非   无[1;35m    ※[1;37m  寸[1;35m  ※
 　   ※       ※                         ※   　 ※
      ※[1;37m   洞[1;35m  ※　  [1;33m埃   物   台   树[1;35m    ※[1;37m  山[1;35m  ※
　    ※       ※                         ※      ※
　    ※　　   ※                         ※      ※
　　  ※※※※※※※※※　　                     ※※※※※※※※[1;37m
LONG);
set("exits", ([ /* sizeof() == 2 */
"north" : __DIR__"gate1",
"southdown": __DIR__"uphill6",
]));

set("objects", ([
                __DIR__"npc/yingke": 1 ]) );
        create_door("north", "石门", "south", DOOR_CLOSED);
         set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        "obj/board/shibei_b"->foo();
}


