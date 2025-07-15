//Cracked by Roath
 // 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
inherit F_FOOD;

void create()
{
  set_name("[1;31m冰糖葫芦[m", ({"bingtang hulu", "hulu"}));
  set_weight(100);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "正宗的冰糖葫芦。\n");
    set("unit", "串");
    set("value", 200);
    set("food_remaining", 5);
    set("food_supply", 35);
  }
}
