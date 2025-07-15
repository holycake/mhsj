
//

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIY"五四式手枪"NOR, ({ "shouqiang" }));
        set_weight(20000);
        set("long", HIG"警用手枪,里面装满了子弹。\n"NOR );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("material", "stone");
		set("value", 2000);
                set("no_get", 1);
		set("amount",30);
        }
        setup();
}

