// calling necklace.c 
// by kittt

#include <ansi.h>

inherit ITEM;

void init()
{
	add_action("do_yell", "yell");
	add_action("do_curb", "curb");
}

void create()
{
	set_name(CYN"呼叫项圈"NOR, ({"necklace", "lace"}));
        set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "套上之随叫随到。\n");
		set("value", 0);
	}

	setup();
}

int do_curb(string arg)
{
	object obj,me = this_player();
	object ob;

	if( !arg ) {
		write("You are curbbing "+ (me->query_temp("curbbing"))->name()+".\n");
		return 1; }

	if(arg=="none" && (ob = me->query_temp("curbbing"))) {
		me->delete_temp("curbbing");
		tell_object(ob,HIR"You are free now!!\n"NOR);		
		ob->set("name",ob->query_temp("oldname"));
		ob->delete_temp("oldname"); 
		write("You are not curbbing anyone now.\n"); 
		return 1;}

	if(!objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if( !userp(obj))
		return notify_fail("你只能套玩家。\n");

	if(obj == me)  
		return notify_fail("自己还套自己？\n");

	if(obj == me->query_temp("curbbing")) 
			return notify_fail("you are already curbbing him/her.\n");

	message_vision(BLU"$N在$n的脖子上套上呼叫项圈。\n" NOR,me,obj);
	obj->set_temp("oldname",obj->name());
	obj->set("name","脖子上套着项圈的"+obj->query("name"));
	if(ob = me->query_temp("curbbing")) {
		tell_object(ob,HIR"You are free now!!\n");		
		ob->set("name",ob->query_temp("oldname"));
		ob->delete_temp("oldname"); }
	me->set_temp("curbbing",obj);
	return 1;
}

int do_yell(string arg)
{
	object ob,me=this_player();

	if( !arg ) return notify_fail("who do you wanna yell??\n");

	if(!(ob = LOGIN_D->find_body(arg)))
			return notify_fail("没有这个人。\n");
 
	if(ob!=me->query_temp("curbbing")) 
			return notify_fail("you are not curbbing him/her.\n");

	if(present(ob, environment(me))) 
		return notify_fail("You guys are already in the same room lah.\n");

	message_vision(HIW"$N大声叫道："+ob->query_temp("oldname")+"！！！！\n" NOR,me);
		message_vision(BLU"$N隐约听到有人在叫$N，身子便不由自主地往那个方向跑去。\n"NOR,ob);
		ob->move(environment(me));
	message_vision("$N来到了$n身边。\n",ob,me);
	return 1;
}

