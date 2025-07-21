#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(WHT"鱼鳞叶"RED"齐腰明甲"NOR, ({ "yuling jia", "armor", "jia" }));
	set_weight(40000);
	if (clonep())
		set_default_object(__FILE__);

	set("unit", "件");
	set("long", "将领所穿的鱼鳞叶齐腰明甲，方领，对襟，无袖，通身缀鱼鳞叶甲片。甲身饰以金蟒纹及毛皮缘边，底边饰彩色排穗。\n");
	set("value", 3000);
	set("material", "steel");
	set("armor_prop/armor", 240);
	set("armor_prop/str", 5);
	set("armor_prop/con", 5);
	set("armor_prop/dex", 2);
	set("armor_prop/personality", 7);
	set("armor_prop/kar", 7);

	setup();
}
int query_autoload() { return 1; }