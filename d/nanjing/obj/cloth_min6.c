#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIR"红色曳撒"NOR, ({ "hong yisan", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","上至王公贵族，下至平民都爱穿戴的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 800);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/per", 1+random(3));
	}

        setup();
}
int query_autoload() { return 1; }