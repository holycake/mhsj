#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"湖蓝云肩通袖龙襕直身袍"NOR, ({ "hulan pao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","皇帝陛下的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 50000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/personality", 3+random(5));
	}

        setup();
}
int query_autoload() { return 1; }