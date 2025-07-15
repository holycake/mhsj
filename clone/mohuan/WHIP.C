// blade.c

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
        set_name(BLU "魔幻神鞭" NOR, ({"whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long",BLINK WHT"由本站的巫师特别为玩家制作的。\n"NOR);
                set("unit", "条");
                set("value", 0);
        }
        init_whip(85);
        setup();
}

