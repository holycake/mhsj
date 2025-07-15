// jinjia.c 金甲
#include <armor.h>

#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name( HIY "金环锁子甲" NOR, ({"golden armor","jinjia", "jia", "armor"}));
        set_weight(20000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
     set("long", HIC"一件金线织就的宝甲．\n"NOR);
                set("material", "steel");
                set("value", 0);

                set("no_give", 1);

                set("no_sell", 1);

                set("no_get", 1);

                set("no_put", 1);

                set("no_sell", 1);

                set("armor_prop/armor", 20);
                set("armor_prop/dodge", -5);
        }
        setup();
}


