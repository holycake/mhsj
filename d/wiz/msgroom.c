// Room: /u/rainy/sea/huilang1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
      set ("short", HIY "信息中心" NOR);
  set ("long", @LONG

这里是魔幻世纪信息中心，在这里你可以使用以下命令：
（addmsg，listmsg，delmsg）
LONG);

  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"jobroom",
]));
          set("objects", 
          ([ //sizeof() == 1
                     "/adm/daemons/msgd" : 1,
          ]));
  setup();
}
