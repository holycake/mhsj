#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
		set_name(HIC"缀珍珠"HIB"天蓝丝带"NOR, ({ "zhenzhu dai", "head", "dai", "bang" }));

		set_weight(10);
		if (clonep())
		        set_default_object(__FILE__);
		else {
		        set("unit", "条");
		        set("long","未成年的女孩子用来扎头发的。\n");
		        set("value", 50);
		        set("material", "hat");
		        set("armor_prop/armor", 2);
		        set("armor_prop/per", 1+random(2));
		        set("wear_msg", HIC "$N" HIC "将$n绑在头发上。");
		        set("remove_msg", HIC "$N" HIC "幽幽的叹了"
		                          "口气，把$n" HIC "从头上扯了下来。\n");
			set("female_only", 1);
		}
		setup();
}

int query_autoload() { return 1; }