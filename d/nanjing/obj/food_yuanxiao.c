inherit ITEM;
inherit F_LIQUID;
#include <ansi.h>

void create()
{
	set_name("赤豆酒酿元宵", ({"chidou yuanxiao", "chidou", "yuanxiao"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "赤豆元宵是用红豆沙煮的小元宵和莲子，再用藕粉勾芡。\n绵密的赤豆，糯糯的小圆子，加入桂花、酒酿，软糯香甜，回味无穷。 \n");
		set("unit", "碗");
		set("value", 5);
        set("max_liquid", 4);
    }

    // because a container can contain different liquid
    // we set it to contain tea at the beginning
    set("liquid", ([
        "type": "water",
        "name": "赤豆酒酿元宵",
        "remaining": 12,
        "drunk_supply": 20,
    ]));
}
