//Cracked by Roath
// zhangchu.c 掌厨僧
// By Dream Dec. 20, 1996

inherit NPC;

string *have_yao=({});
string *have_dan=({});

string ask_yao(object who);
string ask_dan(object who);

void create()
{
	set_name("掌厨僧", ({ "zhangchu seng", "seng" }));
	set("gender", "男性");
	set("age", 25);
	set("attitude", "peaceful");
	set("class", "bonze");
	set("max_kee", 200);
	set("max_gin", 200);
	set("max_sen", 200);
	set("force", 100);
	set("max_force", 100);
	set("force_factor", 10);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 10);
	set("combat_exp", 5000);
	set("daoxing", 10000);
	set_skill("literate", 20);
	set_skill("unarmed", 25);
	set_skill("dodge", 20);
	set_skill("parry", 25);
	set_skill("force", 10);
	set_skill("spells", 10);
	set_skill("buddhism", 10);
	set_skill("unarmed", 30);
	map_skill("spells", "buddhism");
//	set("chat_chance_combat", 80);
//	set("chat_msg_combat", ({
//		(: cast_spell, "thunder" :),
//	}) );

	set("inquiry", ([
		"云南白药": (: ask_yao :),
		"灵丹": (: ask_dan :),
	]) );
        set("apply/yaono", 10);
        set("apply/danno", 10);

        create_family("南海普陀山", 4, "弟子");
	
	setup();
	add_money("silver", 20);
	carry_object("/d/nanhai/obj/sengpao")->wear();
}

string ask_yao(object me)
{
	object ob, who = this_player();
	int number;

        if (who->query("family/family_name") != "南海普陀山") 
		return RANK_D->query_respect(who) +"与本门毫无渊源，为什么问起这个？\n";

if (present("yunnan baiyao", who)) return "你身上不是已经有云南白药了吗，怎么又来要？\n";
	
	if (!(number = me->query("apply/yaono"))) return "对不起，云南白药已经全部发放出去了。\n";
	
	if(member_array(who->query("id"),have_yao)!=-1)
	    return "你不是刚刚要过吗？\n";
	have_yao+=({who->query("id")});

	set("apply/yaono", --number);

	ob = new("/d/ourhome/obj/yunnandrug");
	ob -> move(me);
	command("give " + who->query("id") + " yunnan baiyao");
	return "云南白药得之不易，要节约着用。\n";
}

string ask_dan(object me)
{
	object ob, who = this_player();
	int number;

	if (who->query("family/family_name") != "南海普陀山")
		return RANK_D->query_respect(who) +"与本门毫无渊源，为什么问起这个？\n";

	if (present("lingdan", who)) return "你身上不是已经有灵丹了吗，怎么又来要？\n";

	if (!(number = me->query("apply/danno"))) return "对不起，灵丹已经全部发放出去了。\n";

	if(member_array(who->query("id"),have_dan)!=-1)
	    return "你不是刚刚要过吗？\n";
	have_dan+=({who->query("id")});

	set("apply/danno", --number);

	ob = new("/d/nanhai/obj/lingdan");
	ob -> move(me);
	command("give " + who->query("id") + " lingdan");
	return "灵丹得之不易，要节约着用。\n";
}

