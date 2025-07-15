#include <armor.h>
#include <ansi.h>

inherit BOOTS;

void create()
{
  set_name( HIR"红靴子"NOR, ({ "red shoes", "pixue", "xue" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "双");
    set("long", "一双红色长筒皮靴。\n");
    set("value", 50);
    set("material", "boots");
    set("armor_prop/dodge", 1);
  }
  setup();
}

