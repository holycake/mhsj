// skirt.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIG "轻纱长裙" NOR, ({ "skirt", "cloth" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "一条朦朦胧胧的纱裙，闻起来还有一股淡香。\n");
		set("unit", "条");
		set("material", "cloth");
		set("armor_prop/armor", 110);
		set("armor_prop/intelligence", 5);
		set("armor_prop/personality", 3);
		set("female_only", 1);
	}
	setup();
}

