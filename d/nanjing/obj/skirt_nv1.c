#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(GRN"油绿连裙"NOR, ({ "youlv lian", "skirt" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","常见款式的女子下裙。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 5000);
        	set("armor_prop/armor", 14);
        	set("armor_prop/personality", 3+random(2));
	}

        setup();
}
int query_autoload() { return 1; }