// gangjian.c

#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("[1;32m祖母绿钻石[m", ({"diamon" }));
        set_weight(6000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一粒千年难见得祖母绿宝石,n");
                set("value", 2000);
                set("material", "steel");
                set("wield_msg", "$N从兜里掏出一把$n握在手中。\n");
                set("unwield_msg", "$N将手中的$n放会兜里。\n");
        }
        init_dagger(25,0);
        setup();
}
