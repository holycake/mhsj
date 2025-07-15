//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/shulin1.c

inherit ROOM;

void create ()
{
  set ("short", "[33m树林[m");
  set ("long", @LONG

这里尽是些参天大树，你一走进来，就迷失了方向，只觉得四周只是
一片墨绿，周围景色都是一样的。

LONG);

  set("exits", ([
        "north":__DIR__"shulin9",
        "east" : __DIR__"shulin7",
        "west" : __DIR__"shulin5",
        "south": __DIR__"shulin5",
      ]));
  setup();
}
