
inherit ROOM;

void create ()
{
  set ("short", "偏厅");
  set ("long", @LONG

偏厅布置的颇为优雅，丝毫没有正厅上的严肃气氛。一张红木
大桌边上有个书柜，柜里摆了各式各样的书。墙上挂着几幅字画。
看来客人少时，这里又可以当书房用。
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"zhengting",
      "westup" : __DIR__"duchang1",
        "eastup" : __DIR__"duchang2",
]));
  set("objects", ([
        __DIR__"npc/fujiang"   : 1,
       "/d/kaifeng/npc/zhubing"   : 3,
      ]));

  setup();
}
