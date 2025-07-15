// by gslxz@mhsj 2001/9/26
#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = YEL"杏仁酥"NOR;
  set_name(name, ({"xingren su", "su", "xingren"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一块香甜的"+name+"。\n");
    set("unit", "块");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
