// ironarmor.c
#include <armor.h>
#include <ansi.h>

inherit ARMOR;

void create()
{
        set_name(HIR"魔幻战甲"NOR, ({"mohuan armor", "jia", "armor"}));
        set_weight(30000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
	        set("long", BLINK HIR"由本站的巫师特别为玩家制作的。\n"NOR);
                set("material", "steel");
                set("armor_prop/armor", 55);
		set("armor_prop/dodge", -3);
             }
        setup();
}

