#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
  set ("short", NOR+WHT+U"小茅屋"NOR);
  set ("long", @LONG

这里是天蓬府内院的一间小茅屋，这里是给天蓬府弟子
休息的地方。

LONG);

set("exits", ([ /* sizeof() == 4 */
"east" : __DIR__"zhulin5",
]));

        set("no_clean_up", 0);
        setup();
}

void init()
{
	add_action("do_bed", "gosleep");
	add_action("do_bed", "gobed" );
	add_action("do_bed", "bed");
}

int do_bed()
{       object me;
        me=this_player();
      	message_vision(HIY "$N掀开纱帐，准备上床了。\n\n" NOR, me);
  	me->move("/d/tianpeng/bed");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
         	return 1;
}
