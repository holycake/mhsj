// peace antenna.c
// by kittt

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(RED"和平天线" NOR, ({ "peace antenna","antenna" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
	      set("long","世界和平万岁！！\n");
		set("value", 0);
	}
	setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{
	object me,*ob;
	int i;

	me = this_player();

	if( !arg || arg!="antenna" )
		return notify_fail("what do you wanna use?\n");

	if( me->is_fighting() )
		return notify_fail("it's so irony, you are fighting ya!!\n");

	ob = all_inventory(environment(me));
	message_vision(HIW "$N打开了和平天线。\n" NOR,me);

	ob = all_inventory(environment(me));
	for(i=0; i<sizeof(ob); i++) {
		if( !living(ob[i]) || !ob[i]->is_fighting() ) continue;
		message_vision("$N不由自主地停止了战斗。\n\n" ,ob[i]);
		ob[i]->remove_all_enemy();
		add("num",1);
	}
		if(!query("num")) write("没都没有人打架，你发什麽疯？\n");
			else delete("num");
		return 1;
}

