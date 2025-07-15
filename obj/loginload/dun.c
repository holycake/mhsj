
// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>

inherit SHIELD;

void create()
{
   set_name(HIB"智慧"HIR"之盾"NOR, ({"wisdom shield","shield", "dun"}));
    set("value", 0);
   set_weight(6000);
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("material", "wood");
     set("armor_prop/armor", 20);
   set("armor_prop/dodge", -2);
                 set("armor_prop/intelligence", 10);
  }
  set("no_sell",1);
  setup();
}