// created by snowcat
// 5/22/1997

#include <weapon.h>
#include <armor.h>
#include "hair.h"

inherit NECK;

void create()
{
  set_name("绯色毫毛", ({ "scarlet hair", "scarlethair", "hair" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long", "一把绯红色的毫毛，可以用来变成项链（transform）。\n");
    set("unit", "把");
    set("value",10000);
    set("material","hair");
    set("armor_prop/armor",1);
  }
  set("no_drop",1);
  set("no_get",1);
  set("no_sell",1);
  setup();
}

string name_suffix()
{
  return "项链";
}

string new_unit()
{
  return "串";
}

int init ()  
{   
  add_action ("do_transform", "transform");
  add_action ("do_wear", "wear");
  return 1;
}

int do_wear (string arg)
{
  object me = this_player();
  object ob = this_object();

  if (!arg || present (arg,environment(ob))!=ob)
    return 0; // to invoke standard function
  if (!ob->query("has_transformed")) {
    tell_object (me,"请先将它变成你所需要的项链。\n");
    return 1;
  }
  return 0; // to invoke standard function
}

