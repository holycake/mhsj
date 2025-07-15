#include <ansi.h>
#include <armor.h>;

inherit BOOTS;

void create()
{
        set_name(WHT"大马靴"NOR, ({ "maxue","shoes" }) );
           set("value", 10000);
            set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
 	        set("long", WHT"这是特制的大马靴。\n"NOR);
                             set("material", "steel");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 10);
        }
        setup();
}

