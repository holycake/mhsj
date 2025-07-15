#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(HIW"百宝袋"NOR, ({ "bag" }) );
        set_weight(0);
        set_max_encumbrance(100000000);
		set_max_items(100000000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "口");
                set("long",BLINK HIC"这是本站巫师为大家设计的神奇道具。\n"NOR);
                set("value", 50000);
        }
}

int is_container() { return 1; }

