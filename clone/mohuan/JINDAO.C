#include <weapon.h>
#include <ansi.h>;

inherit BLADE;

void create()
{
        set_name(HIY"魔幻金刀"NOR, ({"blade"}));
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", BLINK HIY"这是本站的巫师为给为玩家做的精良武器\n"NOR);
                set("value", 0);
                set("material", "gold");
                set("wield_msg", "$N「唰」地一声抽出一把$n握在手中，金光闪闪！\n");
                set("unwield_msg", "$N将手中的$n插入魔幻金色刀鞘。\n");
        set("weapon_prop/courage", 15);

        }
        init_blade(95);
        setup();
}

