//cglaem...12/12/96.

inherit ROOM;

void create ()
{
  set ("short", "泾水之滨");
  set ("long", @LONG

泾水东去，绿杨城郭。漫步于此，你不由得心旷神怡，长长
地吸了一口气。而微风中一股清新气息，不知由何处飘来。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ph",
    "east" : __DIR__"wside4",
//  "south" : __DIR__"lichunyuan",
]));
  set("outdoors", 1);

  setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "south" && (int)me->query("age") < 18 && !wizardp(me))
                return notify_fail("小朋友不要到那种地方去！！\n");
        return 1;
}
