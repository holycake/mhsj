#include <weapon.h>

inherit STAFF;

void create()
{
  set_name("压皮杖", ({ "huntie zhang", "zhang", "staff" }) );
  init_staff(35);
  set("unit", "根");
  set_weight(1000);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 200);
    set("material", "iron");
  }
  setup();
}

