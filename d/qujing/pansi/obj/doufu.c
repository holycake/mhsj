// by snowcat 11/20/1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("煎豆腐", ({"jian doufu", "doufu", "fu"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一碗煎得两面黄的豆腐，散发着奇怪的腥味。\n");
    set("unit", "碗");
    set("value", 300);
    set("food_remaining", 4);
    set("food_supply", 50);
  }
}

void init ()
{
  add_action ("do_eat", "eat");
}

int do_eat (string arg)
{
  object who = this_player();
  object me = this_object();
  object ob = present (arg,who);

  if (ob != me)
    return 0;

  remove_call_out ("reacting");
  call_out ("reacting",2+random(4),who);    
  return ::do_eat(arg);
}

void reacting (object who)
{
  if (! who)
    return;

  message_vision("$N一阵子恶心，差点儿吐出来。\n",who);
}
