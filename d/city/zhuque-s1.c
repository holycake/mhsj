//changan city

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short","朱雀大街");
  set ("long", @LONG

朱雀大街上商家众多，大大小小的店铺比邻而立，看起来是相当的豪
华富足。宽阔的石板路直通南北，向北通到皇宫的朝阳门，向南可遥
望到青青的终南山。路东是家大的客栈，来往旅人不绝，西边是家当
铺，出出入入的人有喜有忧。
LONG);

  set("outdoors", "changan");
  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"center",
  "south" : __DIR__"zhuque-s2",
  "west" : __DIR__"dangpu",
  "east" : __DIR__"kezhan",
]));

  set("objects", ([
    __DIR__"npc/jieding" : 1,
  ]));
  setup();
}
int valid_leave(object me, string dir)
{
       /*iif (dir == "east" ) {
       f( me->query_temp("ridee") )
        return notify_fail("你还是先给我从坐骑上下来吧。\n");
        }*/
        if( me->query("quest") )
        me->delete("quest");
        return ::valid_leave(me, dir);
}

