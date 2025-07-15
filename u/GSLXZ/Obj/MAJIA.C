// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIM"小马甲"NOR, ({"majia"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","这是西瓜太郎专门为青云制作的粉红色的小马甲，青云穿上后很像......heihei自己想吧。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}

