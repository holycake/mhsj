
#include <weapon.h>

inherit FORK;

void create()
{
        set_name("[1;32;44m阎王见都怕[m", ({ "fork" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("no_drop",1);
                set("no_put",1);
//                set("no_give",1);
                               set("unit", "柄");
                set("value", 1000);
                set("material", "iron");
                set("long", "一柄锋利的钢叉。\n");
                set("wield_msg", "$N抄起一柄$n，还拿衣服擦了擦叉尖。\n");
        }
        init_fork(190);
        setup();

}
