inherit ROOM;
#include <ansi.h>
void create ()
{
	set ("short","小岛");
	set ("long", @LONG

小岛上别无他物只有一棵参天古树(tree)。
LONG);
      set("item_desc", 
         ([ 
         "tree" : "一棵参天古树如果轻功高的话可以爬(climb)上去。\n"]));
        set("outdoors", "changan");
        setup();
}

void init()
{
  add_action("do_climb", "climb");
}

int do_climb(string arg)
{
  object me=this_player();
  if( (!arg) || !((arg == "tree") || (arg == "树")))
   return notify_fail("你要爬什么？\n");
   if(me->query_skill("dodge", 1) > 119)
   {
   message_vision(HIG"$N奋力向树上爬去，不一会便爬到树枝之间金光闪烁之地。\n"NOR, me);
   me->move(__DIR__"tree");
   return 1;
   }
 else 
  {
   message_vision(HIR"$N奋力向树上爬去，突然你胸中一窒，一个跟头从树上摔了下来！\n"NOR, me);
   me->add("max_force", -1);
   me->receive_damage("kee", 200);
  }
  return 1;
}
