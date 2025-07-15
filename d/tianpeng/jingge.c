#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", "藏经阁");
  set ("long", @LONG

这里是天蓬府后院的阁楼，是天蓬府收藏典籍的地方。靠
墙是一排书架，摆满了天蓬府的典籍。中央有一个长方形
的大桌子，上面也堆满了书。
LONG);        
 set("exits", ([
                "down" : __DIR__"lu1",
      ]));
  set("objects", ([
            "/d/obj/book/xbuddhism"   : 1,
                   "/d/obj/book/luny"   : 1,
                   "/d/obj/book/chaizhao"   : 1,
      ]));

  setup();
}


