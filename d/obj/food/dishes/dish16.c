// by snowcat oct 15 1997

inherit ITEM;
inherit F_FOOD;

void create()
{
  string name = "细扒头肉";
  set_name(name, ({"xipa tourou", "tourou", "rou"}));
  set_weight(1000);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "一盘令人垂涎的"+name+"。\n");
    set("unit", "盘");
    set("value", 250);
    set("food_remaining", 5);
    set("food_supply", 25);
  }
}
