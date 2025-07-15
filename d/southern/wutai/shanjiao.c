#include <ansi.h>
inherit ROOM;

void create()
{
set("short", "五台山脚下");
set("long", @LONG
    

　　从此以北的方圆五百余里，就都是五台山了，共有五座山峰，
五峰拱卫连绵，从山谷吹来的习习凉风使这块小盆地的沟沟洼洼
里，到处都有美的色彩与施律。

LONG );


set("exits", ([
  "northup"   : __DIR__"qinglianggu",
  "south"   : __DIR__"guandao1",
    "northeast" : "/d/12gong/toby1",
 
]));

set("objects", ([ 
]));

set("outdoors", 1);
setup();
}

int valid_leave(object me, string dir)
{
      if(me->query("combat_exp") < 2500000 && dir=="northeast")
       return notify_fail(HIY"你现在的武学修为还没有资格见雅典娜！\n"NOR);
      if(me->query("12gong/number") >= 12 && !me->query("12gong/all") && dir=="northeast" && !wizardp(me))
       return notify_fail(HIR"你不是已经过完12宫了吗？\n"NOR);
       return ::valid_leave(me, dir);
  }
