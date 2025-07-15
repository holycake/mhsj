// dapeng.c...weiqi, 97.09.27.

#include <ansi.h>
inherit NPC;
inherit F_MASTER;
void create()
{
          set_name(HIM"大鹏明王"NOR, ({"dapeng mingwang", "dapeng", "mingwang", "wang"}));
          set("title", HIW"雪山"HIY"之祖"NOR);
	set("gender", "男性" );
	set("age", 45);
	set("per", 30);
	set("str", 30);
	set("long", "这位大鹏明王的确大有来历，说起来跟佛祖如来也有点亲戚关系，\n算是如来的“舅舅”。他不似其兄孔雀明王作恶多端，却也并非善类，\n且因其兄之故跟佛门结下深仇。生平最讨厌的就是和尚。\n");
	set("class", "yaomo");
	set("combat_exp", 1800000);
	set("daoxing", 3000000);

	set("attitude", "peaceful");
	create_family("大雪山", 1, "祖师");
	set("rank_info/respect", "明王");
        set_skill("unarmed", 999);
        set_skill("cuixin-zhang", 999);
        set_skill("dodge", 999);
        set_skill("xiaoyaoyou", 999);
        set_skill("parry", 999);
        set_skill("sword", 999);
        set_skill("bainiao-jian", 999);
        set_skill("blade", 999);
        set_skill("bingpo-blade", 999);
        set_skill("throwing", 999);
        set_skill("force", 999);   
        set_skill("ningxie-force", 999);
        set_skill("literate", 999);
        set_skill("spells", 999);
        set_skill("dengxian-dafa", 999);
	map_skill("spells", "dengxian-dafa");
	map_skill("force", "ningxie-force");
	map_skill("unarmed", "cuixin-zhang");
	map_skill("sword", "bainiao-jian");
	map_skill("blade", "bingpo-blade");
	map_skill("dodge", "xiaoyaoyou");

	set("max_kee", 3500);
	set("max_sen", 3500);
	set("force", 3500);
	set("max_force", 1800);
	set("mana", 4000);
	set("max_mana", 2000);	
	set("force_factor", 120);
	set("mana_factor", 100);

	set_temp("apply/damage", 50);
	set_temp("spply/armor", 50);
	set_temp("apply/dodge", 50);
       set("chat_chance_combat", 50);
       set("chat_msg_combat", ({
                (: cast_spell, "juanbi" :),
                (: cast_spell, "tuntian" :),
                (: perform_action, "sword", "chaofeng" :),

       }) );
            setup();
	carry_object("/d/obj/cloth/choupao")->wear();
	carry_object("d/obj/weapon/sword/qinghong")->wield();
}

void attempt_apprentice(object ob)
{
	if( (string)ob->query("class")=="bonze" && (string)ob->query("gender")=="男性"  )
	{
		command("kick " + ob->query("id"));
		command("say 快走，快走！我一看到和尚就有气。\n");
		return;
	}

	if( (string)ob->query("family/family_name")=="大雪山" ){
		if( (int)ob->query("family/generation") > 3   ){
			command("say 没有四大护法的推荐，本王很难考虑。\n");
		}
		else {
			if( (int)ob->query("daoxing")+(int)ob->query("combat_exp") >= 500000 ){
				command("nod ");
				command("say 好，" + RANK_D->query_respect(ob) + "好好跟我干，将来大有可为！\n");
				command("recruit " + ob->query("id") );
			}
			else {
				command("say 你还是找青狮，白象他们先练着吧。\n");
			}
		}
	}

	else{
		command("hmm");
		command("say 这位" + RANK_D->query_respect(ob) + "，在本门可没有一步登天的事。\n");
	}

	return;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		ob->set("class", "yaomo");
}

void init()
{       
	object ob=this_player();

	::init();
	if ( ((string)ob->query("gender")=="男性") && ((string)ob->query("class")=="bonze") && (random(3) > 1) )
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	
	switch( random(1) ) {
		case 0:
			command("kick " + ob->query("id"));
			command("say 死贼秃！");
			break;
	}
}


