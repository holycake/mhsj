#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
  set_name(MAG"勇者之盾"NOR, ({"yongzhe dun", "dun"}));
    set("value", 20000);
   set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
     set("value", 30000);
   set("material", "wood");
   set("armor_prop/armor", 45);
   set("armor_prop/dodge", -2);
  }
  set("no_sell",1);
  setup();
}
