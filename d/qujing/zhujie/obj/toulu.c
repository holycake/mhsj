// by suannai 2001
#include <weapon.h>

inherit ITEM;

void create()
{
  set_name("头颅", ({"tou lu", "toulu"}));
  set_weight(80);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("long", "这是一颗血淋淋的头颅。\n");
    set("unit", "颗");
    set("material", "bone");
  }
  setup();
}