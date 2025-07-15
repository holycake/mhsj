// rake.c

#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
  set_name("竹钯"NOR, ({ "zhu pa", "pa","rake" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 8000);
    set("material", "iron");
    set("long", "一柄长长的竹耙。\n");
    set("wield_msg", "$N抡起一柄$n，呼地一声举过头顶。\n");
  }
  init_rake(35);
  setup();
}


