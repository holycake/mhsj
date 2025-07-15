#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(WHT"火铳手战裙"NOR, ({ "huochong zhan", "skirt" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","两幅，表里俱用绵布，甲裳用铁丁钉甲片于裳内。围在腰部，裙腰系结于身前。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 35);
        	set("armor_prop/per", 1+random(2));
	}

        setup();
}
int query_autoload() { return 1; }