// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIY"张三丰"NOR, ({ "zhang sanfeng", "zhang" }));
	set("nickname", "百变真人");
	set("long", 
		"他就是武当派开山鼻祖、当今武林的泰山北斗张三丰真人。\n"
		"身穿一件污秽的灰色道袍，不修边幅。\n"
		"身材高大，年满百岁，满脸红光，须眉皆白。\n");
	set("gender", "男性");
	set("age", 100);
	set("attitude", "friendly");
       set("title",HIR "开山祖师" NOR);
       set("rank_info/respect", "老师祖");
	set("shen_type", 1);
	set("str", 30);
          set("per", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	
	set("max_kee", 5000);
	set("max_sen", 5000);
	set("force", 20000);
	set("max_force", 10000);
       set("max_mana", 8000);
       set("mana", 16000);	
       set("force_factor", 120);
       set("mana_factor", 120);
	set("combat_exp", 9500000);
	set("daoxing", 6000000);

	set_skill("force", 999);
	set_skill("wudang-force", 999);
	set_skill("dodge", 999);
	set_skill("tiyunzong", 999);
	set_skill("unarmed", 999);
	set_skill("taiji-quan", 999);
       set_skill("spells", 999);
	set_skill("parry", 999);
	set_skill("sword", 999);
	set_skill("taiji-jian", 999);
	set_skill("wudang-spells", 999);
	set_skill("literate", 999);

	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");
	map_skill("spells", "wudang-spells");

	create_family("武当派", 1, "弟子" );
	set("class", "taoist");

         set("chat_chance_combat", 30);
       set("chat_msg_combat", ({
            (: perform_action, "sword", "taiji" :),
             }) );
	setup();
  /*if ("/d/wudang1/obj/zhenwureal"->in_mud())
    carry_object("/d/wudang1/obj/zhenwufake")->wield();
  else
    carry_object("/d/wudang1/obj/zhenwureal")->wield();*/
    carry_object("/d/wudang1/obj/zhenwu")->wield();

}
 void destruct_me (object me)
{
  destruct (me);
}


void attempt_apprentice(object ob)
{
	if ((int)ob->query_skill("wudang-force", 1) < 600) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在武当心法上多下点功夫？");
		return;
	}
	if ((int)ob->query("daoxing") < 2000000) {
		command("say 学武之人，德义为先，功夫的高低倒还在其次，未练武，要先学做人。");
		command("say 在德行方面，" + RANK_D->query_respect(ob) +
			"是否还做得不够？");
		return;
	}
	if (ob->query_int() < 30) {
		command("say 我武当派武功全从道藏悟出。");
		command("say 要能达到炉火纯青之境，体质什么的倒是无关紧要，悟性却是半点也马虎不得。");
		command("say " + RANK_D->query_respect(ob) + "的悟性还大有潜力可挖，还是请回吧。");
		return;
	}
	command("chat 哈哈哈哈！！！！");
	command("chat 想不到老道在垂死之年，又觅得一个可塑之才，真是可喜可贺。");
	command("recruit " + ob->query("id"));
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ){
                ob->set("class", "taoist");
}
        return 0;
}


