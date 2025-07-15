inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name("桂花糖芋苗", ({"tang yumiao", "yumiao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "光洁的芋苗口感润滑爽口、香甜酥软，汤汁呈酱红色鲜亮诱人，散发着浓郁的桂花香，吃后唇齿留香。\n");
		set("unit", "碗");
		set("value", 5);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "桂花糖芋苗",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}
