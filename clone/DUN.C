#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
  set_name(MAG"紫萝藤盾"NOR, ({"ziluo dun", "dun"}));
  set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 200);
   set("material", "wood");
   set("armor_prop/armor", 35);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
  setup();
}