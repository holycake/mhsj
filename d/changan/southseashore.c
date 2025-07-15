// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// Room: /changan/southseashore.c
//cglaem...12/12/96.
#include <ansi.h>

inherit ROOM;
int do_dive();

void create ()
{
  set ("short", "南海之滨");
  set ("long", @LONG

南海之滨。往北是一条宽阔笔直的官道，足可容得下十马并驰。
往南则是一片汪洋大海，不知通向何方。西南海面上隐隐可见
一小岛。浅海近岸处还有几个游泳的人。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"broadway5",
   "west" : __DIR__"jiaoshi",
  "east" : __DIR__"seashore1",
]));
  set("outdoors", 1);

  setup();
}


void init()
{
        add_action("do_swim", "swim");
    add_action("do_dive", "dive");
}

int do_swim()
{
        object me = this_player();
        
message_vision(HIY "$N纵身一跃，跳入海中。只见$N使足了全身力气，手足并用，不一会儿就游到了海中小岛上。\n" NOR, me);
   if (me->query_temp("ridee"))
     me->query_temp("ridee")->set_temp("rider",0);
   me->set_temp("ridee",0);
   me->add_temp("apply/dodge",-me->query_temp("ride/dodge"));
   me->set_temp("ride/dodge",0);

        me->move("/d/nanhai/island");
        message_vision(HIY "只见$N浑身湿漉漉地从海里爬了上来。\n" NOR, me);
        me->receive_damage("kee", 20);
        me->receive_damage("sen", 20);
        return 1;
}

int do_dive()
{       object me, zhou;
    object ridee;
        me=this_player();
   ridee=me->ride();



	    if(( !(zhou=present("bishui zhou", me))
		||(string)zhou->query("unit")!="张")
		&& (string)me->query("family/family_name")!="龙宫"
                  && (string)me->query("family/family_name")!="东海龙宫"
                  && (string)me->query("family/family_name")!="天蓬府")

		return notify_fail("你一个猛子扎到水里．．．\n"+
		  "\n但没多会儿就被憋得半死，只好赶紧爬上岸来。\n");

   if (ridee && ridee->query("under_water")) {
     message_vision(HIY"$N一拍$n的头，连人带马跃入水中。\n"NOR,me,ridee);
     ridee->move("/d/southsea/under1");
  }

      else  message_vision(HIY "$N一个猛子扎到水中，然后不见了．\n" NOR, me);
                me->move("/d/southsea/under1");
		message_vision("$N潜了过来。\n",me);
                return 1;
}




