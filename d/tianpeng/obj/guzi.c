//By mhsj@gslxz 2001/07/28

#include <ansi.h>

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"谷子"NOR, ({"guzi", "gu", "zi"}));
        set_weight(300);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "一捧谷子。\n");
                set("unit", "捧");
                set("value", 0);
            	  set("no_give", 1);
		  set("no_sell", 1);
                set("food_remaining", 2);
                set("food_supply", 100);
        }
  setup();

}

int init ()  
{   
  add_action ("do_eat", "eat");
  return 1;
}

string rdm(string *strs)
{
  return strs[random(sizeof(strs))];
}

int do_eat (string arg)
{

  if (arg != this_object()->query("id"))
    return 0;

  message_vision( "$N将一捧"HIY"谷子"NOR"放进嘴里，嚼了起来。\n" NOR, this_player(),this_object());
  this_player()->set("food", (int)this_player()->max_food_capacity());
  this_player()->set("water", (int)this_player()->max_water_capacity());
  destruct(this_object());
  return 1;
}

