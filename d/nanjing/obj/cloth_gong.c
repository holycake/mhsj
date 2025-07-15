#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"内宫夹袄"NOR, ({ "nei ao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","夹袄，领部有白色护领，用金纽扣纽系。袖口接白色袖缘，衣身两侧在腋下开衩。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/per", 3+random(3));
			set("female_only", 1);
	}

        setup();
}
int query_autoload() { return 1; }