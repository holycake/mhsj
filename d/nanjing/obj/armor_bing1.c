#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIC"青苎丝长身甲"NOR, ({ "qing zhusi", "armor", "jia" }));

        set_weight(5000);
        if (clonep())
        	set_default_object(__FILE__);

    	set("long","一般士兵的布罩甲，长身甲，对襟，无袖，通身缀金属丁。\n");
    	set("material", "cloth");
    	set("unit", "件");
    	set("value", 3000);
    	set("armor_prop/armor", 180);
		set("armor_prop/str", 2);
		set("armor_prop/con", 2);
		set("armor_prop/dex", 5);
		set("armor_prop/personality", 2);

        setup();
}
int query_autoload() { return 1; }