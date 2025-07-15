// jinjia.c 金甲
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HIY "GANDAMα合金" NOR, ({"hejin"}));
        set_weight(50000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一种硬度奇高的金属。\n");
                set("material", "steel");
                set("value", 2000000);
                set("armor_prop/armor", 500);
		set("armor_prop/dodge", -10);
        }
        setup();
}



