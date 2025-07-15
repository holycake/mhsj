#include <ansi.h>
#include <armor.h>;

inherit HEAD;

void create()
{
set_name(HIC"魔幻世纪"HIY"纪念章" NOR, ({ "jinianzhang" }) );
  set_weight(1);
  if( clonep() )
    set_default_object(__FILE__);
  else {
  set("unit", "枚");
   set("long",HIY"本站开站纪念章。\n"NOR);
    set("material", "cloth");
    set("armor_prop/armor", 15);
set("armor_prop/spells", 50);
set("armor_prop/force", 50);
set("value", 500000);
}
  setup();
}
