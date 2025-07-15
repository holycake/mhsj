// by snowcat oct 15 1997
#include <ansi.h>;

#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(HIY"锦戎袈裟"NOR, ({"jia sha", "cloth"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "一件袈裟。\n");
    set("material", "cloth");
    set("unit", "件");
    set("value", 600);
    set("armor_prop/armor", 80);
  }
  setup();
}

