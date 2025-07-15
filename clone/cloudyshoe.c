#include <ansi.h>
#include <armor.h>;

inherit BOOTS;

void create()
{
        set_name(HIC "踏云靴" NOR, ({ "cloudy shoes", "shoes" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
                set("material", "cloth");
                set("armor_prop/armor", 2);
                set("armor_prop/dodge", 10);
        }
        setup();
}

