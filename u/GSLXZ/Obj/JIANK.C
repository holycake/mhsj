
//

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIC"监控器"NOR, ({ "jiankqi" }));
        set_weight(20000);
        set("long", "这台监控器可以监控到本站的每个角落。\n" );
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

