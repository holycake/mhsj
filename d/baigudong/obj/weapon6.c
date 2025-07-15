#include <weapon.h>

inherit RAKE;

void create()
{
  set_name("清骨耙", ({ "zhushan pa", "pa", "rake" }) );
  init_rake(35);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 320);
    set("material", "iron");
  }
  setup();
}

