#include <ansi.h>

inherit MONEY;

void create()
{
        set_name(HIY"金币", ({"jinbi", "jinbi_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("money_id", "jinbi");
               set("long", HIY"一枚仙侣情缘的硬币，正面是神龙和媚儿的新婚像，反面是全体巫师的全家福。\n"NOR);
                set("unit", "枚");
               set("base_value", 10000000);
                set("base_unit", "枚");
		set("base_weight", 3);
	}
	set_amount(1);
}

