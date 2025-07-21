#include <ansi.h>
//choupao.c

#include <armor.h>

inherit CLOTH;

void create()
{
	switch(random(5))
	{
		case 0: set_name(HIR"大红"HIY"金龙纹"HIR"百子衣"NOR, ({ "honglong baizi", "cloth", "pao" }));break;
		case 1: set_name(HIC"翠蓝"HIY"遍地金龙纹"HIC"百子衣"NOR, ({ "cuilan baizi", "cloth", "pao" }));break;
		case 2: set_name(RED"红素罗"HIY"地洒线绣平金龙百子花卉"RED"方领女夹衣"NOR, ({ "hongsu yi", "cloth", "pao" }));break;
		case 3: set_name(RED"红素罗"HIY"绣金龙百子图"RED"方领女袄"NOR, ({ "hongsu ao","cloth", "pao" }));break;
		case 4: set_name(GRN"绿织"HIY"金妆花云肩通袖龙纹"NOR""GRN"缎女夹衣"NOR, ({ "lvzhi yi", "cloth", "pao" }));break;
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
		set("armor_prop/personality", 4+random(5));
		set("female_only", 1);
	}

	setup();
}
int query_autoload() { return 1; }