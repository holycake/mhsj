#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
		set_name(HIB"大帽"NOR, ({ "da mao","mao", "jin" }));

		set_weight(10);
		if (clonep())
		        set_default_object(__FILE__);
		else {
		        set("unit", "顶");
		        set("long","上至王公贵族，下至平民都爱穿戴的日常头服。\n");
		        set("value", 500);
		        set("material", "hat");
		        set("armor_prop/armor", 10);
		        set("armor_prop/warm", 3);
		        set("armor_prop/per", 1+random(2));
		        set("wear_msg", HIC "$N" HIC "双手捧起$n，端正地放在头上。");
		        set("remove_msg", HIC "$N" HIC "幽幽的叹了"
		                          "口气，把$n" HIC "从头上摘了下来。\n");
		}
		setup();
}

int query_autoload() { return 1; }