#include <ansi.h>
#include <armor.h>;

inherit BOOTS;

void create()
{
        set_name(HIW"晶莹冰雪鞋"NOR, ({ "iceshoes","shoes" }) );
         set("value", 30000);
            set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
 	        set("long", HIW"这是由晶莹的冰做成的鞋。\n"NOR);
                             set("material", "steel");
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 20);
        }
        setup();
}

