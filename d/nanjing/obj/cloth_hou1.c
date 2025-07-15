#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	switch(random(5))
	{
		case 0: set_name(RED"红地"HIY"织金缠枝莲妆花"NOR""RED"缎女夹衣"NOR, ({ "hongdi yi", "cloth", "pao" }));break;
		case 1: set_name(RED"红"HIY"织金缠枝"HIM"牡丹妆花"RED"纱袄"NOR, ({ "mudan ao", "cloth", "pao" }));break;
		case 2: set_name(HIR"大红"HIY"织金缠枝牡丹妆花"WHT"绣“洪福齐天”"HIR"女夹衣"NOR, ({ "hongfu yi", "cloth", "pao" }));break;
		case 3: set_name(RED"红地"HIY"织金吉庆双鱼妆花"NOR""RED"缎女夹衣"NOR, ({ "shuangyu yi", "cloth", "pao" }));break;
		case 4: set_name(RED"紫红地"HIY"大凤莲孔雀羽织金妆花"NOR""RED"缎女夹衣"NOR, ({ "kongque yi", "cloth", "pao" }));break;
	}
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("long","后妃的常服。\n");
		set("material", "cloth");
		set("unit", "件");
		set("value", 50000);
		set("armor_prop/armor", 15);
		set("armor_prop/warm", 7);
		set("armor_prop/per", 4+random(5));
		set("female_only", 1);
	}

	setup();
}
int query_autoload() { return 1; }