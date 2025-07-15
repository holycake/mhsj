// zhujian.c 竹箭

#include <weapon.h>

inherit ARCHERY;

void create()
{
  set_name("竹箭", ({ "zhu jian", "arrow", "jian" }) );
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("long",
"竹子削成的箭，箭头削尖，箭尾胡乱插了些羽毛。\n");
    set("unit", "壶");
    set("base_unit", "枝");
    set("base_weight", 20);
    set("base_value", 10);
  }
  set_amount(10);
  set("value", 100);
  init_archery(10);
  setup();
}

