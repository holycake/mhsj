// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(MAG"天王紫金袍"NOR, ({"zhanpao","cloth"}));
    set("value", 40000);
      set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",MAG "一件由紫金制作而成的战炮。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}

