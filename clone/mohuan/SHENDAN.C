
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

  void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
    set_name( HIG "魔幻神丹" NOR , ({"mohuan dan", "dan"}));
  set_weight(90);
  if (clonep())
      set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long",BLINK+HIG "本站巫师为各位玩家特别制作的补药。\n"NOR);
      set("value", 3000000);
    set("drug_type", "补品");
   }
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="dan" && arg!="mohuan dan")	return 0;
  
    me->set("eff_sen", (int)me->query("max_sen"));
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());

 
  message_vision(HIR"$N吞下一颗传说中的"HIG"魔幻神丹"+HIR"顿时$N感到气血畅通，
精神焕发，内力充沛。\n" NOR, me);
destruct(this_object());
  
 return 1;
}

