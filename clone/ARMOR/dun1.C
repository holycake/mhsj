#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
  set_name(HIG"紫藤青萝盾"NOR, ({"qingluo dun", "dun"}));
   set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
     set("value", 20000);
   set("material", "wood");
   set("armor_prop/armor", 45);
   set("armor_prop/dodge", -2);
  }
    setup();
}
