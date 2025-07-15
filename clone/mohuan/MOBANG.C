#include <weapon.h>
#include <ansi.h>

inherit STICK;

void create()
{
        set_name(HIC "魔幻神棒" NOR, ({"mohuan shenbang", "bang"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
		set("no_sell", 1);
		set("long", BLINK HIY"由本站的巫师特别为玩家制作的。\n"NOR);
                set("value", 0);
                set("material", "steel");
                set("wield_msg", "$N「呼」地一声抽出一把$n握在手中。\n");
        }
        init_stick(80);
        setup();
}

