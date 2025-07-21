#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIR"红布罩甲"NOR, ({ "hong jia", "armor", "cloth", "jia" }));

        set_weight(5000);
        if (clonep())
        	set_default_object(__FILE__);

    	set("long","皇城禁卫兵的布罩甲，胸背处缀有方补，衣身两侧及后部开裾，底边饰彩色排穗。\n");
    	set("material", "cloth");
    	set("unit", "件");
    	set("value", 3000);
    	set("armor_prop/armor", 180);
		set("armor_prop/dodge", 7);
		set("armor_prop/str", 2);
		set("armor_prop/con", 2);
		set("armor_prop/dex", 5);
		set("armor_prop/personality", 5);

        setup();
}
int query_autoload() { return 1; }