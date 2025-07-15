#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(HIM"内宫马面裙"NOR, ({ "nei mamian", "skirt" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","马面裙，裙摆宽大，两侧有三角形裙片。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/per", 2+random(3));
	}

        setup();
}
int query_autoload() { return 1; }