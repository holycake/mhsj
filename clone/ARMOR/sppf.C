#include <ansi.h>
#include <armor.h>;

inherit SURCOAT;

void create()
{
  set_name(CYN "兽皮披风" NOR, ({"shoupipifeng", "pifeng","cloth"}));
     set("value", 20000);
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",CYN"这是由非常华里的兽皮制作而成的。\n"NOR);
    set("material", "leather");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}


