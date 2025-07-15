#include <ansi.h>
#include <armor.h>

inherit ARMOR;

void create()
{
	set_name(HIY"金对襟"HIC"长身罩甲式"HIR"明甲"NOR, ({ "jin jia", "armor", "jia" }));

	set_weight(40000);
	if (clonep())
		set_default_object(__FILE__);

	set("unit", "件");
	set("long", "对襟长身罩甲式明甲，用金纽扣纽系，两侧及后身开裾，底边饰彩色排穗，胸部缀有护心镜，两肩用掩膊，缀红色肩缨。\n");
	set("value", 3000);
	set("material", "steel");
	set("armor_prop/armor", 220);
	set("armor_prop/str", 5);
	set("armor_prop/con", 5);
	set("armor_prop/dex", 2);
	set("armor_prop/per", 6);
	set("armor_prop/kar", 6);

	setup();
}
int query_autoload() { return 1; }