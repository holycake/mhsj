// yinjia.c 银甲
#include <ansi.h>
#include <armor.h>;

inherit ARMOR;

void create()
{
        set_name(HIW "银环锁子甲" NOR, ({"silveren armor","yinjia", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
		set("long", "一件银丝织就的宝甲．\n");
                set("material", "steel");
                set("armor_prop/armor", 60);
		set("armor_prop/dodge", -5);
        }
        setup();
}



