// rake.c

#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
  set_name(HIC"钢钯"NOR, ({ "gang pa", "pa","rake" }) );
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 8000);
    set("material", "iron");
    set("long", "一柄长长的钢耙。\n");
    set("wield_msg", "$N抡起一柄$n，呼地一声举过头顶。\n");
  }
  init_rake(75);
  setup();
}


