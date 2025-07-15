#include <ansi.h>
//choupao.c

#include <armor.h>

inherit SKIRT;

void create()
{
	set_name(WHT"乳白色亵裤"NOR, ({ "xieku" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","行房事时用以增加情趣的衣物。宽松的衣物包裹着下体，摸起来手感相当细腻。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/per", 1+random(3));
	}

        setup();
}
int query_autoload() { return 1; }