#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIG"翠"HIB"蓝长袄"NOR, ({ "cuilan ao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","国朝女子的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 500);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
              set("armor_prop/personality", 2+random(5));
		set("female_only", 1);
	}

        setup();
}
int query_autoload() { return 1; }