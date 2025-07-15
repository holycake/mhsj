#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("法轮", ({ "falun","lun","hammer" }) );
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                  set("long", "常见的法器，没什么看头\n");
                set("value", 3000);
                set("material", "iron");
                set("wield_msg", "$N拿出一个$n，握在手中晃了几下。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(40);
        setup();
}
