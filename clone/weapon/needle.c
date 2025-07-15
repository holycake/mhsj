// gangjian.c
#include <ansi.h>
#include <weapon.h>
inherit NEEDLE;

void create()
{
        set_name("绣花针", ({ "zhen", "needle" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根可以当武器的针.\n");
                set("value", 1);
                set("material", "steel");
                set("wield_msg", "$N袖子一翻,手里面多了一根$n。\n");
                set("unwield_msg", "银光一闪,手中的$n不见了.\n");
        }
        init_needle(15);
        setup();
}
