// handkerchief.c
// by kittt

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIC"时光手帕" NOR, ({ "time handkerchief","time","handkerchief" }) );
	set_weight(100);
	set_max_encumbrance(10000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
	      set("long","能让人变年轻的东西。\n");
		set("value", 0);
		set("material", "silk");
	}
	setup();
}
int is_container() { return 1; }

void init()
{
        add_action("do_wrap","wrap");
        add_action("do_unwrap","unwrap");
}

int do_wrap(string arg)
{
	object me, obj;
	
	me = this_player();

	if( !arg )
		return notify_fail("你想包谁？\n");

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !userp(obj))
		return notify_fail("你只能让玩家变年轻。\n");

	if(obj == me)  
		return notify_fail("you can't wrap yourself.\n");

		message_vision(HIY "$N用时光手帕把$n包了起来。\n" NOR,me,obj);
		obj->move(this_object());
		obj->set_temp("wrap",1);
		tell_object(obj,"你感觉脸上的皱纹消失了，精神也好了不少。\n");
		obj->set("mud_age",obj->query("mud_age")/2);
		return 1;
}

int do_unwrap(string arg)
{
	object me,*inv;
	int i;

	me = this_player();

		inv = all_inventory(this_object());
		if( !sizeof(inv) )
			return notify_fail("nothing in there.\n");

		for(i=0; i<sizeof(inv); i++) {
			if (inv[i]->query_temp("wrap")) {
			message_vision(HIY"$N打开时光手帕，$n充满活力地跳了出来。\n"NOR,me,inv[i]);
			inv[i]->move(environment(me));
 			inv[i]->delete_temp("wrap");
			}
		}
	return 1;
}