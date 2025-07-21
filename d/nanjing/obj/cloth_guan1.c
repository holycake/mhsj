#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIB"蓝色云纹圆领袍"NOR, ({ "lan pao", "cloth", "pao" }));

        set_weight(3000);
        if (clonep())
        	set_default_object(__FILE__);
        else 
	{
        	set("long","圆领袍，织有云纹。胸前有方补。是官员的常服。\n");
        	set("material", "cloth");
        	set("unit", "件");
        	set("value", 2000);
        	set("armor_prop/armor", 15);
        	set("armor_prop/warm", 7);
        	set("armor_prop/personality", 2+random(4));
	}

        setup();
}
int query_autoload() { return 1; }