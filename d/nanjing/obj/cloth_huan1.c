#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIC"内侍青色圆领袍"NOR, ({ "nei pao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","圆领袍，胸背缀补子。是宫廷内侍的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/personality", 1+random(2));
	}

        setup();
}
int query_autoload() { return 1; }