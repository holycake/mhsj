#include <weapon.h>

inherit BLADE;

void create()
{
  set_name("锋蚌刀", ({ "fengbeng dao", "dao", "blade" }) );
  init_blade(25);
  set("unit", "把");
  set_weight(400);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 230);
    set("material", "shell");
  }
  setup();
}

