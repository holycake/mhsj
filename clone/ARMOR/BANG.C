#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
      set_name(RED "天赐"WHT"神威棒" NOR, ({"shenwei bang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
//   set("no_sell", 1)
            set("long", RED"威力巨大的棒。\n"NOR);
   set("value", 30000);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
        }
      init_stick(120);
        setup();
}

