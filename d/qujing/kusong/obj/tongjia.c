//Cracked by Roath
#include <armor.h>

inherit ARMOR;

void create()
{
        set_name("青铜甲", ({"bronze armor","tongjia","jia","armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 3000);
                set("material", "steel");
                set("armor_prop/armor", 40);
             }
                         setup();
}

