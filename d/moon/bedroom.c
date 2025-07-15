//Cracked by Roath
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "卧房");
  set ("long", @LONG

一间淡湖绿色的房间, 三面是书架, 上面摆满了杂七杂八的书，对湖的一
面开了一扇竹窗, 窗前放着一架五弦琴，墙边有一张牙玉色的软榻(bed)
LONG);

  set("no_fight", 1);
  set("item_desc", ([ /* sizeof() == 1 */
  "bed" : "一张牙玉色的软榻，塌四周雕着竹叶格，看上去极为精致(gosleep,gobed,bed)。 
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"rain",
]));
  set("no_magic", 1);

  setup();
}

void init()
{
        add_action("do_bed", "gosleep");
        add_action("do_bed", "gobed", );
        add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
        message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
        me->move(__DIR__"bed");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
                return 1;
}


