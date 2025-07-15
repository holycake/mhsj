#include <ansi.h>
#include <armor.h>;

inherit HEAD;

void create()
{
  set_name(WHT "铁盔" NOR, ({ "tie kui", "tiekui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long","一顶沉重的大铁盔，顶上有一尖柄。\n");
    set("material", "cloth");
    set("armor_prop/armor", 10);
    set("armor_prop/personality", 1);
  }
  setup();
}

