// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIM"粉色吊带裙"NOR, ({"skirt"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","这是西瓜太郎专门为忽悠制作的粉红色的性感吊带裙。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}

