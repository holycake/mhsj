#include <weapon.h>

inherit FORK;

void create()
{
  set_name("白骨叉", ({ "baigu cha", "cha", "fork" }) );
  init_fork(28);
  set("unit", "根");
  set_weight(700);
  if( clonep() )
     set_default_object(__FILE__);
  else {
    set("value", 300);
    set("material", "bone");
  }
  setup();
}

