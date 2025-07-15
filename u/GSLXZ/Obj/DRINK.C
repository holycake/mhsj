
//

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"饮奶机"NOR, ({ "yinnai ji" }));
        set_weight(20000);
        set("long", "这是一台专门出酸奶的机器,有非常好喝的酸奶流出来。\n" );
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

