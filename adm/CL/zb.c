// jinjia.c 金甲
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HBRED+HIY " 合 金 装 备 " NOR, ({"golden armor","hejin", "jia", "armor"}));
        set_weight(1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件纯近造就的宝甲．\n");
                set("material", "steel");
                set("value", 50000);
                set("armor_prop/armor", 500);
set("armor_prop/dodge", 20);
set("armor_prop/spells", 20);
set("armor_prop/force", 20);

        }
        setup();
}



