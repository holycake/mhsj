//Cracked by Roath
#include <weapon.h>

inherit STICK;

void create()
{
  set_name("牛骨棒", ({ "niugu bang", "bang", "stick" }) );
  init_stick(25);
  set("unit", "根");
  set_weight(900);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 70);
    set("material", "bone");
  }
  setup();
}

