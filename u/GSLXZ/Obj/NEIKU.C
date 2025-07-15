// by snowcat oct 15 1997
#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
  set_name(YEL"性感小内裤"NOR, ({"ku"}));
  set_weight(4000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long",BLINK YEL "这是西瓜太郎特地为小宝和桃心太郎设计的人皮色的性感小内裤,非常漂亮呀。\n" NOR);
    set("material", "cloth");
    set("unit", "件");
    set("armor_prop/armor", 90);
  }
  setup();
}

