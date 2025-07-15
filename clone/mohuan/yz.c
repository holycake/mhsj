// snowcat 4/25/97

#include <weapon.h>

inherit THROWING;

void create()
{
    set_name("银针", ({"yin zhen", "zhen"}));
  if( clonep() )
    set_default_object(__FILE__);
  else {
      set("long", "一把细小的绣花针，闪着点点寒芒。\n");
    set("unit", "些");
      set("base_unit", "根");
    set("base_weight", 40);
    set("base_value", 1);
  }
    set_amount(1909);
  set("rigidity",100);
    init_throwing(200);
  setup();
}

