// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name("围裙", ({ "wei qun", "qun" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一条围裙，上面满是动物的脚印。\n");
		set("material", "cloth");
		set("unit", "条");
		set("value", 10000);
		set("armor_prop/armor", 10);
	}
	setup();
}
