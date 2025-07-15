#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(HIM"战裙"NOR, ({ "zhan qun", "skirt" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","制为两幅，围在腰部，裙腰系结于身前。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 95);
	}

        setup();
}
int query_autoload() { return 1; }