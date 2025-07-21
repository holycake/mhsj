#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	set_name(HIM"粉色纱制抹胸"NOR, ({ "moxiong", "neiyi" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long","行房事时用以增加情趣的衣物。会紧紧贴着双乳，让身体的曲线若隐若现。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 70);
		set("armor_prop/armor", 15);
		set("armor_prop/warm", 2);
		set("armor_prop/personality", 2+random(5));
		set("female_only", 1);
	}

	setup();
}
int query_autoload() { return 1; }