//Cracked by Roath
// Room: /d/nanhai/gate
inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "山门");
  set ("long", @LONG

[1;37m这里是南海普陀山的山门，山门上写着：[2;37;0m
  
  [1;35m  ※※※※※※※※※※※※※※※※※※※※※※※※
 　[1;35m ※※※※                                ※※※※
   [1;35m ※※※※   [1;37m净  瓶  甘  露  年  年  盛，[1;35m ※※※※
    [1;35m※※※※                                ※※※※
    [1;35m※※※※   [1;37m斜  插  垂  杨  岁  岁  青。[1;35m ※※※※
    [1;35m※※※※　　　　　　　　　　　　　　    ※※※※　　     
   [1;35m ※※※※  [1;37m 落  伽  山  上  慈  悲  主，[1;35m ※※※※
    [1;35m※※※※                                ※※※※
    [1;35m※※※※   [1;37m潮  音  洞  里  活  观  音。[1;35m ※※※※
    [1;35m※※※※                                ※※※※
    [1;35m※※※※※※※※※※※※※※※※※※※※※※※※[2;37;0m

[1;37m真个仙山宝地，福岛洞天！[2;37;0m

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/zhike" : 1,
]));
  set("outdoors", __DIR__"");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"xiaoyuan",
  "southdown" : __DIR__"shanglu",
]));

  create_door("north", "石门", "south", DOOR_CLOSED);
set("valid_startroom", 1);
setup();

"/obj/board/wall_b"->foo();
}

