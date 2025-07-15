// mihoutao.c 猕猴桃
#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
  add_action("do_eat", "eat");
}
void create()
{
  set_name(HBWHT+BLK "可可豆" NOR, ({"keke dou","keke","dou"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "粒");
    set("long", "黑乎乎的，好像是"HIM"忽悠"NOR"炸胡了的花生耶。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}
int do_eat(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->add_maximum_force(50);
  me->add_maximum_mana(50);
  message_vision(HIG "$N吃下一颗可可豆，脸上露出痛苦的表情，难吃死了！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
