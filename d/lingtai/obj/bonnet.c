#include <armor.h>

inherit HEAD;

void create()
{
        set_name("天师法冠", ({ "loyal bonnet", "bonnet", "hat" }) );
        set_weight(1000);
                set("unit", "顶");
		set("long", "一顶黄色象牙玉法冠。\n");
                set("material", "steel");
                set("value", 1000);
		set("no_sell", 1);
set("armor_prop/armor", 80);
   set("armor_prop/intelligence", 30);
set("armor_prop/personality", 10);
        setup();
}

