// jinqiang.c
// updated 5-30-97 pickle


#include <weapon.h>
#include <ansi.h>

inherit SPEAR;

void create()
{
            set_name(HIY "神威点金枪" NOR, ({ "spear","qiang"}));
  set_weight(14000);
  if( clonep() )
    set_default_object(__FILE__);
  else {
    set("unit", "杆");
  set("value", 30000);
    set("material", "gold");
        set("long", HIY"这是一杆由纯金制作而成的枪。\n"NOR);
    set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
  }
    init_spear(120);
  setup();
}

