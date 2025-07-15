#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(HIY"黄织金云龙"HIB"海水纹"HIY"襕裙"NOR, ({ "yunlong lan", "skirt" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","后妃的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 50000);
        	set("armor_prop/armor", 14);
        	set("armor_prop/per", 3+random(5));
	}

        setup();
}
int query_autoload() { return 1; }