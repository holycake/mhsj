// gangcha.c
#include <ansi.h>

#include <weapon.h>

inherit FORK;

void create()
{
        set_name(HIW"魔幻银叉"NOR, ({ "fork", "cha"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
                set("value", 0);
                set("material", "iron");
                set("long", BLINK HIW"这是本站的巫师为各位玩家制作的精良武器。\n"NOR);
                set("wield_msg", "$N抄起一柄$n轻轻的握在手里。\n");
        }
        init_fork(90);
        setup();
}

