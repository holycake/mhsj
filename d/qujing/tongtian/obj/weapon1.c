#include <weapon.h>

inherit FORK;

void create()
{
  set_name("蟹螯钳", ({ "xieao qian", "qian", "fork" }) );
  init_fork(30);
  set("unit", "把");
  set_weight(500);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 390);
    set("material", "shell");
  }
  setup();
}

