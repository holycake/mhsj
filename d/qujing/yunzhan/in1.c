//Cracked by Roath

//  妖神之争 １。０
//  by happ@YSZZ 2000.4.6
//  /d/qujing/yunzhan/road5.c

inherit ROOM;

void create ()
{
  set ("short", "洞口");
  set ("long", @LONG

一走进来，你发现几个模糊不清的大字：
[32m
                    ⌒⌒⌒⌒⌒⌒⌒⌒⌒
                    ⌒  [1;37m云  栈  洞[0;32m  ⌒
                    ⌒⌒⌒⌒⌒⌒⌒⌒⌒ 
LONG);

  set("exits", ([
        "north"  : __DIR__"in2",
        "up"  : __DIR__"shanlu3",
      ]));
  setup();
}
