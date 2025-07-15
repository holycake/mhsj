#include <ansi.h>
#include <armor.h>;

inherit HEAD;

void create()
{
  set_name(WHT"魔幻天盔" NOR, ({ "tian kui", "tiankui", "kui" }) );
  set_weight(2200);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "顶");
    set("long",BLINK HIR"由本站的巫师特别为玩家制作的。\n"NOR);
    set("material", "cloth");
    set("armor_prop/armor", 15);
    set("armor_prop/personality", 1);
  }
  setup();
}

