#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
		set_name(HIC"尖顶明铁盔"NOR, ({ "jian mingkui", "mao", "kui" }));

		set_weight(10);
		if (clonep())
		        set_default_object(__FILE__);
		else {
		        set("unit", "顶");
		        set("long","尖顶明铁盔，盔顶饰黑缨花及皁绢盔旗，盔下用青苎丝或青绵布顿项，两耳处缀有护耳。\n");
		        set("value", 1000);
		        set("material", "hat");
		        set("armor_prop/armor",80);
		        set("armor_prop/warm", 5);
		        set("armor_prop/per", 1+random(2));
		        set("wear_msg", HIC "$N" HIC "双手捧起$n，端正地放在头上。");
		        set("remove_msg", HIC "$N" HIC "幽幽的叹了"
		                          "口气，把$n" HIC "从头上摘了下来。\n");
		}
		setup();
}

int query_autoload() { return 1; }