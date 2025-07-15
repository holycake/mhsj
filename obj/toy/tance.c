//By waiwai@mszj 2000/10/10

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIW"战斗力探测器"NOR, ({ "tance" }) );
	set_weight(300);
	set("unit", "个");
	set("long",
		HIC"这是专用的战斗力探测器，你可以用它来探测 "+HIR"(tance)"HIC" 别人的武学值。\n");
	set("value", 50000);
	set("no_put", 1);
	set("type", "misc");
	set("apply", ([
		"头部":	0,
	]) );
}

void init()
{
	add_action("do_tance", "tance");
}

int do_tance(string arg)
{
	object ob;
	int sen, sk;
	string skill;

	if( arg ) ob = present(arg, environment(this_player()));
	else ob = this_player()->query_opponent();

      if (this_player()->is_busy())
		return notify_fail("你现在正忙着呢。\n");

	if( !ob ) return notify_fail(HIG"你要探测谁的战斗力？\n"NOR);

	sen = (int)ob->query("sen");
	if( stringp(skill = ob->query("attack_skill")) )
		sk = ob->query_skill(skill);
	else
		sk = 0;

	printf(HIC"探测器显示"+HIB" %s "+HIC"的战斗力是： "+HIR"%d\n"NOR,
		ob->query("name"), 
		(sk*sk*sk) * (100 + sen) / 100 + (int)ob->query("combat_exp") );
  tell_object(ob,HIR"你突然感到好象" HIY+ this_player()->name() +HIR "正在鬼鬼祟祟地探测你......\n"NOR);
      	this_player()->start_busy(3);

	return 1;
}

