//Cracked by Roath
#include <ansi.h>

// ludongbin.c...weiqi, 98.02.24.

string give_book();
string ask_jinguzhou();

inherit NPC;
void create()
{
	set_name(WHT"白发仙人"NOR, ({"baifa xianren", "xianren", "baifa"}));
	set("title", HIC"老神仙"NOR);
	set("gender", "男性" );
	set("age", 35);
	set("per", 30);
	set("long", "一位老神仙。\n");
	set("class", "xian");
	set("combat_exp", 1200000);
  set("daoxing", 8000000);

	set("attitude", "peaceful");
	set_skill("unarmed", 360);
	set_skill("wuxing-quan", 360);
	set_skill("dodge", 380);
	set_skill("baguazhen", 380);
	set_skill("parry", 380);
	set_skill("sword", 390);
	set_skill("sanqing-jian", 300);
	set_skill("force", 370);   
	set_skill("zhenyuan-force", 370);
	set_skill("literate", 320);
	set_skill("spells", 380);
	set_skill("taiyi", 380);
	map_skill("spells", "taiyi");
	map_skill("force", "zhenyuan-force");
	map_skill("unarmed", "wuxing-quan");
	map_skill("sword", "sanqing-jian");
	map_skill("dodge", "baguazhen");

	set("max_kee", 5000);
	set("max_sen", 5000);
	set("force", 10000);
	set("max_force", 8000);
	set("mana", 16000);
	set("max_mana", 8000);	
	set("force_factor", 200);
	set("mana_factor", 200);

	set("inquiry", ([
		"医书" : (: give_book :),		 
	]) );

	set("no_book", 0);

	setup();
	carry_object("/d/obj/cloth/xianpao")->wear();
	carry_object("/d/obj/weapon/sword/qinghong")->wield();
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "xian");
}

string give_book()
{
	object me = this_player();

	if( query("no_book") == 0 )
	{
		carry_object("/d/obj/book/yishu");
		command("give yishu to " + me->query("id"));
		set("no_book", 1);
		return "呵呵！既然是有心人，那我就给你吧。\n";
	}
	else
	{
		return "你来晚了，我的书已经送人了。\n";
	}

}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "在微风中缓缓离去。\n");
    destruct(me);
}
void init()
{
    call_out("self_dest",36+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
	}



