#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(WHT"白绵布甲"NOR, ({ "baimian jia", "armor", "jia" }));

        set_weight(5000);
        if (clonep())
        	set_default_object(__FILE__);

    	set("long","火铳兵的白绵布甲，齐腰式甲衣。里侧钉铁质甲片。缀铁丁以将甲片固定在绵甲内部。两肩各用护肩一幅\n");
    	set("material", "cloth");
    	set("unit", "件");
    	set("value", 3000);
    	set("armor_prop/armor", 180);
		set("armor_prop/dodge", 10);
		set("armor_prop/str", 2);
		set("armor_prop/con", 2);
		set("armor_prop/dex", 5);
		set("armor_prop/personality", 6);

        setup();
}
int query_autoload() { return 1; }