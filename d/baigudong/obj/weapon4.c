#include <weapon.h>

inherit AXE;

void create()
{
  set_name("碎骨斧", ({ "suigu fu", "fu", "axe" }) );
  init_axe(30);
  set("unit", "把");
  set_weight(1100);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "iron");
  }
  setup();
}

