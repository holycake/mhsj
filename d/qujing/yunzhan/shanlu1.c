//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "山路");
  set ("long", @LONG

只见前方的山顶直插云霄，真是个险啊，就连周围的树也是奇
高无比，一棵棵仿佛与天相接，前方有一块石碑，上书：
[33m
                      福   陵   山[m

LONG);

  set("exits", ([
        "eastdown"  : __DIR__"road5",
        "westup"  : __DIR__"shanlu2",
      ]));
  set("outdoors","yz");
  setup();
}
