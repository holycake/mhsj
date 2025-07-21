#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIR"窄袖云肩通袖膝襕袍"NOR, ({ "zhaixiu pao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","武将穿在铠甲里面的衣服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 10);
        	set("armor_prop/personality", 2+random(3));
		set("armor_prop/personality", 1);
	}

        setup();
}
int query_autoload() { return 1; }