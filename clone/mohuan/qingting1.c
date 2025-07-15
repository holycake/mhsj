#include <ansi.h>
#include <armor.h>;

inherit HEAD;

void create()
{
  set_name(HIC"竹蜻蜓" NOR, ({ "qingting" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long",BLINK HIR"这是小叮当的神奇道具。\n"NOR);
    set("material", "cloth");
    set("armor_prop/armor", 15);
    set("armor_prop/personality", 300);
        set("value", 50000);
}
  setup();
}

