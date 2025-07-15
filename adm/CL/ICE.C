
#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松，冰淇淋从指间滑落！\n");
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }
  add_action("do_eat", "eat");
}

void create()
{
  set_name( HIW "冰淇淋" NOR , ({"icecream", "ice"}));
  set_weight(90);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "份");
    set("long", "一份大大的冰淇淋，上面还有一颗樱桃，略微能闻到些许香气。\n");
    set("value", 500000);
    set("drug_type", "补品");
  }
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  if (arg!="ice" && arg!="icecream")   return 0;
  me->set("sen", (int)me->query("max_sen"));
  me->set("eff_sen", (int)me->query("max_sen"));
  me->set("gin", (int)me->query("max_gin"));
  me->set("eff_gin", (int)me->query("max_gin"));
  me->set("kee", (int)me->query("max_kee"));
  me->set("eff_kee", (int)me->query("max_kee"));
  me->set("mana", (int)me->query("max_mana"));
  me->set("force", (int)me->query("max_force"));
  me->set("water", (int)me->max_water_capacity());
  me->set("food", (int)me->max_food_capacity());
  message_vision("$N拿起冰淇淋咬了一口，顿时一股凉意沁入心脾。
只见$N脸上慢慢泛出红晕，看起来有精神多了！\n", me);
  return 1;
}

