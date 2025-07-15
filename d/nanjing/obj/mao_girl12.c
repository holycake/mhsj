#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
		set_name(HIY"金累丝双鸳衔寿果金"HIC"步摇簪"NOR, ({ "yuan zan", "mao", "zan" }));

		set_weight(10);
		if (clonep())
		        set_default_object(__FILE__);
		else {
		        set("unit", "条");
		        set("long","这是未出嫁的女子头面。\n");
		        set("value", 900);
		        set("material", "hat");
		        set("armor_prop/armor", 3);
		        set("armor_prop/per", 2+random(3));
		        set("wear_msg", HIC "$N" HIC "将$n插在头发上。");
		        set("remove_msg", HIC "$N" HIC "幽幽的叹了"
		                          "口气，把$n" HIC "从头上扯了下来。\n");
			set("female_only", 1);
		}
		setup();
}

int query_autoload() { return 1; }