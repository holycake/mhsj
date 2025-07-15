// gate.c

#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", "[1;37m阴阳界[2;37;0m");
  set ("long", @LONG

隐约北方现出一座黑色城楼，光线太暗，看不大清楚。许多亡魂正
哭哭啼啼地列队前进，因为一进鬼门关就无法再回阳间了。周围尺
高的野草随风摇摆，草中发出呼呼的风声。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"new-out2",
  "north" : __DIR__"new-out6",
  "west": __DIR__"new-out8",
  "east": __DIR__"new-out4",
]));
	set("no_fight", 1);
	set("no_magic",1);
  set("hell", 1);
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pang" : 1,
]));

  setup();
}
