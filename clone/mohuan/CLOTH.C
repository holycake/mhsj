// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIG"魔幻褊衫"NOR, ({"cloth"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",BLINK HIY "一件由本站巫师精心制作的褊衫。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}

