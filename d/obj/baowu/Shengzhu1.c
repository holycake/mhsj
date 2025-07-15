#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("圣灵珠", ({"sheng lingzhu"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value",100000);
                set("material", "cloth");
                set("no_sell", "卖?这种稀世之宝谁买得起啊!\n");
                set("long","天地初开时，清者归于上，浊者归于下；有一种半清半浊归于中，是为此宝！\n
因此五行皆为其子。\n");
                set("female_only", 1);
        }
        setup();
}