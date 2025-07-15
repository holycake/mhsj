//Cracked by Roath
// sgzl

#include <weapon.h>

inherit THROWING;

void create()
{
   set_name("绣花针", ({"xiuhua zhen","zhen"}));
   if( clonep() )
            set_default_object(__FILE__);
   else 
     {
      set("long",    "一把细小的绣花针，闪着点点寒芒。\n");
      set("unit", "把");
      set("base_unit", "根");
      set("base_weight", 5);
      set("can_install", 1);
      set("value", 30);
      }
      set_amount(10);
      init_throwing(10);
      setup();
}

