// Room: /u/gslxz/bedroom.c
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "Happy Bar");
  set ("long", @LONG

 这里是西瓜太郎的高级卧房，这里的装饰
比五星级酒店的总统套房，还要舒适。
LONG);
  set("item_desc",(["bed":"睡觉用的床铺(gosleep,gobed,bed)。 \n", ]));
set("outdoors", 0);
  set("chat_room",1);
  set("no_time",1);
          set("sleep_room",1);
        set("if_bed",1);
set("no_time", 1);
set("freeze", 1);
  set("no_fight", 1);
set("chat_room",1);
  set("no_magic", 1);
  set("no_upgrade_age",1);
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));
  set("valid_startroom", 1);
    set("exits", ([ /* sizeof() == 4 */
            "east" : __DIR__"workroom1",
    ]));             
 set("objects", ([
                   "/u/gslxz/npc/baomu2" : 1,
      ]));     
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
  	me->move("/u/gslxz/bed_room");
            message_vision(HIY "\n沙帐轻轻一动，$N钻了进来。\n" NOR, me);
         	return 1;
}
