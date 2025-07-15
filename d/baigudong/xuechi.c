// Room: create by smile 12/10/1998
#include <ansi.h>
inherit ROOM;

void create()
{
  set ("short", HIR "血池" NOR);
  set ("long", @LONG

  [1;31m血池[2;37;0m是白骨精一干妖精平时饮用水
的来源，原本是一口永不枯竭的清泉，自从白骨精占据了
这里作为洞穴后，突然开始流出血红的泉水，白骨精以为
是天佑其人,乃命名为[1;31m血池[2;31;0m。\n
LONG);

  set("exits", ([ /* sizeof() == 1 */
    "west": __DIR__"dongnei",
  ]));

  set("resource", ([ /* sizeof() == 1 */
                     "water" : 1,
                                 ]));

  set("outdoors", __DIR__"");                   
  setup();
}
