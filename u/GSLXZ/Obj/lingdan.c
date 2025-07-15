inherit ITEM;

mapping *poisons = ({
	([	"name": "double_ice_poison",
	]),
	([	"name": "ice_poison",
	]),
	([	"name": "jjf_poison",
	]),
	([	"name": "snake_poison",
	]),
	([	"name": "moon_poison",
	]),
});

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name("解病万灵丹", ({"lingdan", "dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "粒");
		set("long", "这是一颗解病万灵丹，吃下去包解百毒。\n");
		set("value", 50000);
        set("drug_type", "补品");
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_object();
	mapping poison;
	int i,duration;
	if (!id(arg))
		return notify_fail("你要吃什么？\n");
	message_vision("$N拿出一粒解病万灵丹，连忙吞了下去。\n", this_player());
	for(i=0;i<sizeof(poisons);i++) {
                poison=poisons[i];
                duration=me->query_condition(poison["name"]);
                if(duration>0) {
			me->apply_condition(poison["name"], 0);
                }
        }
		destruct(this_object());
		return 1;
}

