// by snowcat 12/2/1997

#include <ansi.h>

inherit ITEM;

void create()
{
  set_name( HIG"辟谷丸"NOR , ({"pigu wan", "wan"}));
  set_weight(120);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一颗黑油油的辟谷丸。\n");
    set("value", 800);
    set("no_sell", 1);
    set("drug_type", "补品");
  }
  setup();
}


void init()
{
  add_action("do_eat", "eat");
}

  
  int do_eat(string arg)
  {
    object me = this_player();
      if (arg!="pigu wan" && arg!="wan") 
      return 0;

  me->set("food", (int)me->max_food_capacity()*3+random(120));
  me->set("water", (int)me->max_water_capacity()*3+random(120));
  message_vision(HIG "$N捏起一颗辟谷丸送进嘴里吞下。\n" NOR, me);
  tell_object(me, "顿时你觉得腹中生热，飘飘欲仙！\n");
  destruct(this_object());
  return 1;
}

