#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(GRN"云龙纹"YEL"双膝襕"GRN"马面裙"NOR, ({ "yunlong mamian", "skirt" }));

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
        	set("armor_prop/personality", 3+random(5));
	}

        setup();
}
int query_autoload() { return 1; }