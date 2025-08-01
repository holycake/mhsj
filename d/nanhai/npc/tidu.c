// by gslxz@mhsj 2001/10/24
// tidu.c

#include <ansi.h>

inherit NPC;

string ask_for_join();
string ask_for_leave();
string ask_for_huansu();

void create()
{
	set_name("剃度僧", ({ "tidu seng", "seng" }) );

	set("gender", "男性");
	set("age", 50);
	set("attitude", "peaceful");
	set("class", "bonze");

	set("str", 17);
	set("int", 30);
	set("spi", 30);
	set("con", 30);
	set("cps", 30);
	set("cor", 20);

	set("atman", 200);
	set("max_atman", 200);

	set("force", 150);
	set("max_force", 150);
	set("force_factor", 5);

	set("mana", 200);
	set("max_mana", 200);

	set("combat_exp", 10000);
	set("daoxing", 50000);

	set("inquiry", ([
		"剃度" : (: ask_for_join :),
		"出家" : (: ask_for_join :),
		"还俗" : (: ask_for_huansu :),
		"脱离" : (: ask_for_leave :),
		"leave" : (: ask_for_leave :),
		]) );

	set_skill("staff", 20);
	set_skill("unarmed", 30);
	set_skill("force", 25);
	set_skill("dodge", 20);
	set_skill("literate", 20);
	set_skill("parry", 20);
	set_skill("spells", 10);

	set_skill("lotusforce", 20);
	set_skill("buddhism", 20);

	map_skill("force", "lotusforce");
	map_skill("spells", "buddhism");

	create_family("南海普陀山", 4, "弟子");

	setup();

	carry_object("/d/nanhai/obj/sengpao")->wear();
}

void init()
{
	add_action("do_kneel", "kneel");
        add_action("do_agree", "agree");
        add_action("do_huansu", "huansu");
}

string ask_for_huansu()
{
	object me;

	me = this_player();

	if( (string)me->query("bonze/class")!="bonze" )
		return "阿弥陀佛！你既已身系尘世，何必凑这个热闹？\n";
	me->set_temp("pending/leave_bonze", 1);
command("say 阿弥陀佛！一入俗世，万劫不复，"+RANK_D->query_respect(me)+"一身大乘佛法也将随之付诸东流。还望"+RANK_D->query_respect(me)+"三思。");
	return RANK_D->query_respect(me)+"若已决定，便请脱袍还俗(huansu)。\n";
}

int do_huansu()
{
        if( !this_player()->query_temp("pending/leave_bonze") ) return 0;
	message_vision( HIC "$N脱下身上的袈裟，恭恭敬敬地跪下来磕了几个响头，从此恢复了自由身。\n\n"NOR, this_player(), this_object() );
	this_player()->delete("class");
	this_player()->delete("bonze/class");
	this_player()->delete_skill("buddhism");
	command("say 从今以後你恢复出家前的俗名" +this_player()->query("bonze/old_name")+"。");
	this_player()->set("name", this_player()->query("bonze/old_name") );
	command("sigh");
        this_player()->delete_temp("pending/leave_bonze");
	this_player()->save();
	return 1;
}

string ask_for_join()
{
	object me;

	me = this_player();

	if (me->query("married"))
		return "阿弥陀佛！施主有了家庭拖累，想必难以潜心向佛。\n";
	if( (string)me->query("bonze/class")=="bonze" )
		return "阿弥陀佛！你我同是出家人，何故跟老衲开这等玩笑？\n";
	if( me->query("bonze/justonetime"))
		return "施主既已还俗，又何苦再次出家？\n";
	me->set_temp("pending/join_bonze", 1);
	return "阿弥陀佛！善哉！善哉！施主若真心皈依我佛，请跪下(kneel)受戒。\n";
}

int do_kneel()
{
	string *prename1 =
	 ({ "普","智","悟","渡","空", "明", "虚", "法" });
	string *prename2 =
	 ({ "文", "净", "方", "慧" });
	string name, new_name;

	if( !this_player()->query_temp("pending/join_bonze") ) return 0;
	message_vision(	HIC "$N双手合十，恭恭敬敬地跪了下来。\n\n" + 
			"$n伸出手掌，在$N头顶轻轻地摩挲了几下，将$N的头发尽数剃去。\n\n" NOR,
		this_player(), this_object() );
	name = this_player()->query("name");
	new_name = ( (string)this_player()->query("gender") == "男性" )? 
		prename1[random(sizeof(prename1))] + name[0..1]
		:prename2[random(sizeof(prename2))] + name[0..1];
	 message("shout", WHT "〖剃度出家〗剃度僧(Tidu seng)："+ "从今日起"+YEL""+this_player()->name()+NOR+WHT"皈依我佛，法名" HIY+ new_name +NOR+WHT "。\n"NOR,users());
	command("say 从今以後你的法名叫做" + new_name + "。");
	command("smile");
	this_player()->delete_temp("pending/join_bonze");
	this_player()->set("name", new_name);
	this_player()->set("bonze/class", "bonze");
	this_player()->set("bonze/justonetime", 1);
	this_player()->set("bonze/old_name", name);
        this_player()->set("class", "bonze");
	this_player()->save();
	return 1;
}

string ask_for_leave()
{
	object me=this_player();

	if (me->query("family/family_name") == "南海普陀山" ) {
		command("say 你既是执意下山，贫僧却有几句话说。");
		me->set_temp("betray", 1);
		return ("脱离师门要需要有一定惩罚，你可愿意(agree)?\n");
	}

	return ("贫僧不知。\n");
}
			
			
int do_agree(string arg)
{
	if(this_player()->query_temp("betray") &&
		this_player()->query("family/family_name") == "南海普陀山") {
		message_vision("$N答道：弟子愿意。\n\n", this_player());
		this_player()->add("betray/putuo", 1);
		this_player()->add("betray/count", 1);
		command("say 既是你与佛门无缘，你便下山去吧！\n");

		this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
		this_player()->set("daoxing", this_player()->query("daoxing")*80/100);

		this_player()->delete("family");
		this_player()->delete("class");
		this_player()->delete_skill("buddhism");
		this_player()->set("title", "普通百姓");
		this_player()->set_temp("betray", 0);
		command("say 江湖风波，善恶无形，好自为之。。。\n");
		this_player()->save();
		return 1;
	}

}

