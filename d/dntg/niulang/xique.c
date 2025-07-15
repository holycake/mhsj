//By canoe 2001.03.26
// 能吃，哈哈
#include <ansi.h>;
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name(HIC"喜鹊"NOR, ({"xique"}));
  set_weight(60);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一只能呼朋引伴的喜鹊。\n");
    set("unit", "只");
    set("value", 0);
    set("food_remaining", 5);
    set("food_supply", 30);
  }
}
