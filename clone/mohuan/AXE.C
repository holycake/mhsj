// hammer.c
#include <ansi.h>
#include <weapon.h>

inherit AXE;

void create()
{
        set_name(YEL"魔幻神斧"NOR, ({"axe"}));
        set_weight(12000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long",
 BLINK HIY"这是本站的巫师为给为玩家做的精良武器\n"NOR);
                set("value", 0);
                set("material", "iron");
                set("wield_msg",
"$N拿出一把$n握在手中，眼前闪过一道寒光．\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }

        init_axe(90);
        setup();
}

