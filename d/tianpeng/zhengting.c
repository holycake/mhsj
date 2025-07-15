#include <ansi.h>

inherit ROOM;
void create ()
{
  set ("short", HBRED" 天蓬府正厅 "NOR);
  set ("long", @LONG

这里布置的颇为优雅，几个家将站立两旁，也许是因为没
有人说话，厅上的气氛很严肃。

              [1;37m  天    蓬    府    第[2;37;0m

LONG);

  set("exits", ([
          "north"   : "/d/tianpeng/lu",
        "west"   : "/d/kaifeng/shuaifu",
               "south" : __DIR__"pianting",
      ]));
  set("objects", ([
        __DIR__"npc/zhangmen"   : 1,
      ]));

  setup();
}


