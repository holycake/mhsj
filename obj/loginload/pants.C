// by gslxz_mhsj 2001/12/12
#include <ansi.h>
#include <armor.h>

inherit PANTS;

void create()
{
  set_name(HIC"青色长裤"NOR, ({"pants","ku"}));
    set("value", 0);
    set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
//    set("long",MAG "传说,穿上它就会拥有无穷的智慧。\n" NOR);
    set("material", "pants");
    set("unit", "件");
    set("armor_prop/armor", 90);
  set("armor_prop/intelligence", 5);
 }
  setup();
}

