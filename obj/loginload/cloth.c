// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(HIR"英雄大氅"NOR, ({"hero cloth","cloth"}));
    set("value", 0);
      set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "cloth");
    set("unit", "件");
        set("armor_prop/armor",20);
 }
  setup();
}