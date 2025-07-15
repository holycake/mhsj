#include <weapon.h>
inherit NEEDLE;

void create()
{
        set_name("织锦针", ({ "zhen", "needle" }));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "这是妲己炼神针的时候丢掉一些次品.\n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N袖子一翻,手里面多了一根$n。\n");
                set("unwield_msg", "银光一闪,手中的$n不见了.\n");
        }
        init_needle(70);
        setup();
}
