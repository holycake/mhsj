#include <ansi.h>
#include <armor.h>;

inherit BOOTS;

void create()
{
        set_name(HIC"魔幻飞靴"NOR, ({ "shoes" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "双");
 	        set("long", BLINK HIR"由本站的巫师特别为玩家制作的。\n"NOR);
                             set("material", "steel");
                set("armor_prop/armor", 5);
                set("armor_prop/dodge", 10);
        }
        setup();
}

