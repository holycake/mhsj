// cloth.c
//
// This is the basic equip for players just login.

#include <armor.h>

inherit CLOTH;

void create()
{
        string *order=({"粗布", "棉布", "蓝布", "洗得发白的",
"青布","紫布","黑布","白布"});
        set_name((order[random(8)]) +"少林僧衣", ({ "monk clothes", "clothes"}) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("shaolin_cloth",1);
		set("value",10);
		set("material", "cloth");
		set("armor_prop/armor", 20);
	}
	setup();
}
