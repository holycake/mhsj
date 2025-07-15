// rake.c

#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
  set_name(HIG"寒雪碧玉钯"NOR, ({ "yu pa", "pa","rake" }) );
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "柄");
    set("value", 80000);
    set("material", "iron");
    set("long", HIG"此钯是由碧玉做成的。\n"NOR);
    set("wield_msg", "$N抡起一柄$n，呼地一声举过头顶。\n");
  }
  init_rake(35);
  setup();
}


