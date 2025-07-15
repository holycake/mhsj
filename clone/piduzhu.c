// by gslxz@mhsj 6/1/2001

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"辟毒珠"NOR , ({"pidu zhu", "zhu"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗珍贵的辟毒珠。\n");
       set("value", 2000000);
    set("drug_type", "仙丹");
  }
  setup();
}

int init ()
{ if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的辟毒珠，哪能乱扔! \n");
                set("no_give","这么宝贵的辟毒珠，还是自己留着吧! \n");
//                        set("no_sell","这么贵的东西，人家怎么买的起! \n");
  }

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


