//Cracked by Roath
//  by happ@YSZZ 2000.4.5
//  /d/qujing/heifeng/in2.c

inherit ROOM;

void create ()
{
  set ("short", "洞中");
  set ("long", @LONG

这是整个洞穴的中间，令人奇怪的是路的两旁居然有一幅对联：
[33m
                 静  静  深  山  无  俗  虑
                 幽  居  仙  洞  乐  天  真
[m
LONG);

  set("exits", ([
        "southup"  : __DIR__"cave",
        "north"  : __DIR__"in1",
        "west"   : __DIR__"in5",
        ]));
   set("objects",([
        __DIR__"npc/yaojing":2,
        ]));
  setup();
}
