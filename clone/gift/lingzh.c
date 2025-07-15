// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void create()
{
	set_name(HIR "万年灵芝" NOR, ({"ling zhi", "zhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("long", "这是一棵武林人士梦寐以求的万年灵芝，据说吃一棵可得1000经验，500潜能。\n");
		set("value", 0);
	}
	setup();
}

int do_eat(string arg)
{
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

	this_player()->add("combat_exp", 0);
	this_player()->add("potential",0);
	message_vision("$N吃下一棵万年灵芝，$N眨了眨眼睛，好像没有什么作用，原来是假的!\n", this_player());
	destruct(this_object());
	return 1;
}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "落在地上，不见了。\n");
    destruct(me);
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "rumor", 
	    this_player()->name()+"在"HIW+
	         	MISC_D->find_place(environment(this_player()))+HIM"得到了传说中的"+name()+HIM"！\n");
}
void init()
{ 
	add_action("do_eat", "eat");
       call_out("self_dest",1200000+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
}


