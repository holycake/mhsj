// by gslxz@mhsj 6/1/2001

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"辟毒丹"NOR , ({"pidu dan", "dan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗珍贵的辟毒珠。\n");
      set("value", 50000);
    set("drug_type", "仙丹");
  }
  setup();
}

int init ()
{
  add_action ("do_jiedu","jiedu");
 return 1;
}
int do_jiedu (string arg)
{
  string *msgs = ({
    "$N"HIG"将解毒珠用力在身上摩擦。\n"NOR,
  });
  object me = this_player(1);

  if (me->is_busy())
    return notify_fail (HIG"你现在正忙着，不能替自己解毒！\n"NOR);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->start_busy(1/2,0);if ((me->query("kar")+me->query_temp("spring/cure_times")) > 1)
  {
    if (! me->update_condition())
      return 1;     
message_vision ("$N"HIR"忽然从嘴里吐出一滩黑血，身上的毒已经清除了。\n"NOR,me);
    me->clear_condition();
  destruct(this_object());
//    me->unconcious();
  }   
me->add_temp("spring/cure_times",1);
  return 1;
}

int valid_leave(object me, string dir)
{
  me->delete_temp("spring/cure_times",1);
//  return ::valid_leave(me, dir);
}


