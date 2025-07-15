
//

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN"对讲机"NOR, ({ "duijiangji" }));
        set_weight(20000);
        set("long", HIG"这是警用通讯器材。\n"NOR );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "台");
                set("material", "stone");
		set("value", 2000);
                set("no_get", 1);
		set("amount",30);
        }
        setup();
}

