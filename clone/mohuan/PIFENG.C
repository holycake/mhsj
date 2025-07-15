#include <ansi.h>
#include <armor.h>;

inherit SURCOAT;

void create()
{
  set_name(HIB "魔幻披风" NOR, ({"pifeng", "cloth"}));
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",BLINK HIR"由本站的巫师特别为玩家制作的。\n"NOR);
    set("material", "leather");
    set("unit", "件");
    set("armor_prop/armor", 45);
  }
  setup();
}


