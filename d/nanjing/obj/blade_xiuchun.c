#include <ansi.h>
//blade.c

#include <weapon.h>

inherit BLADE;

void create()
{
	string desc;
	set_name(HIR"绣春刀"NOR, ({"xiuchun dao", "blade", "dao"}));
	set_weight(4000);
	if (clonep())
		set_default_object(__FILE__);
	else 
	{
		set("unit", "柄");
		set("value", 5000);
		set("material", "iron");
		switch(random(3))
        	{
        	case 0: desc="这是把精钢打造，棕竹刀鞘，红\n色棉线缠柄的装具古朴的锦衣卫佩刀。\n";init_blade(41);break;
        	case 1: desc="这是把百炼精钢打造，檀木刀鞘\n，红色丝线缠柄的装具精致的锦衣卫佩刀。\n";init_blade(43);break;
        	case 2: desc="这是把夹钢工艺打造，檀木刀鞘\n，刀鞘和刀柄皆包以鲨鱼皮的装具考究的锦衣卫佩刀。\n";init_blade(46);break;
        	}
		set("long", "此刀比一般的刀略长，单双手皆可持握。刀名典出杜少陵的诗句\n“绣衣春当霄汉立，彩服日向庭闱趋”。"+desc);
		set("wield_msg", "$N抽出一把明晃晃的$n握在手中。\n");
		set("unequip_msg", "$N将手中的$n插入腰间的刀鞘。\n");
	}
	

	setup();
}

int query_autoload() { return 1; }
