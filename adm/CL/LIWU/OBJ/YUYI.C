// yuyi.c

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
	set_name(HIW"羽衣"NOR, ({ "yu yi", "yi" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是一件由羽毛制成的衣服，虽然很薄，却极为暖活。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 1000000);
		set("wear_msg", HIW "只听「刷」的一声，$N展开一件白色的羽衣身上。\n" NOR);
		set("remove_msg", HIW "$N将羽衣从身上脱了下来，折叠成小小的一团。\n" NOR);
		set("armor_prop/armor", 1000);
	}
	setup();
}
