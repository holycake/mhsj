// Room: /d/sky/nantianmen
 
#include <room.h>
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short", "凌虚殿");
  set ("long", @LONG


LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east"      : __DIR__"yunlue1",
  "west"      : __DIR__"tongmingdian",

]));




  setup();
}
 
