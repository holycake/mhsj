#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(MAG"紫色行衣"NOR, ({ "zi yi", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","上至王公贵族，下至平民都爱穿戴的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 600);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/personality", 1+random(3));
	}

        setup();
}
int query_autoload() { return 1; }