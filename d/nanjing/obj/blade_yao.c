#include <ansi.h>
//blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(WHT"腰刀"NOR, ({"yao dao", "blade", "dao"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "柄");
		set("value", 5000);
		set("material", "iron");
/*		switch(random(3))
        	{
        	case 0: desc="这是把精钢打造，棕竹刀鞘，红\n色棉线缠柄的装具古朴的锦衣卫佩刀。\n";init_blade(32);break;
        	case 1: desc="这是把百炼精钢打造，檀木刀鞘\n，红色丝线缠柄的装具精致的锦衣卫佩刀。\n";init_blade(38);break;
        	case 2: desc="这是把夹钢工艺打造，檀木刀鞘\n，刀鞘和刀柄皆包以鲨鱼皮的装具考究的锦衣卫佩刀。\n";init_blade(45);break;
        	}*/
		set("long", "国朝军队常用的腰刀。");
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	init_blade(35);

	setup();
}

int query_autoload() { return 1; }
