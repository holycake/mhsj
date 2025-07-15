#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
{
        set_name(HIR"红帽子"NOR, ({ "red hat", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
		set("long", "一顶红色的帽子。\n");
                set("material", "steel");
                set("value", 100);
                set("armor_prop/armor", 1);
		set("armor_prop/personality", 1);
        }
        setup();
}

