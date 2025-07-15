// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short",HIM"搏饼别院  "HIY"魔幻世纪道具店"HIR BLINK" →   "NOR);
        set("long", @LONG

这里是一处很幽静的地方，有一石桌和若干石凳，四周是一片绿色
的树林，隐约还能闻到桂花的香味，看着边上那条静静流着的小溪，
你心中不禁泛起逝者如斯的感慨，在这微微的伤感中，轻叹一声：
又到中秋了．．．
LONG);

        set("exits", ([
		"up" : "/d/city/kezhan",
                  "north" : "/d/wiz/bobing",
                  "south" : "/d/area/room",
                  "east" : "/d/wiz/daoju",
//                  "north" : "/d/wiz/clubpoem",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
               "/u/gslxz/npc/huang" : 1,
                 "/d/wiz/obj/bei" : 1,
]));
        setup();
}
