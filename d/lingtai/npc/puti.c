// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("菩提祖师", ({"master puti","puti", "master"}));
       set("long", "大觉金仙没垢姿，西方妙相祖菩提\n");
       set("title", WHT"斜月三星"NOR);
       set("gender", "男性");
       set("age", 100);
	set("class", "taoist");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老师祖");
       set("per", 26);
	set("looking", "玉面多光润，苍髯颌下飘，金睛飞火焰，长目过眉梢。");
	set("int", 30);
       set("max_kee", 5000);
       set("max_gin", 5000);
       set("max_sen", 5000);
       set("force", 12000);
       set("max_force", 6000);
       set("force_factor", 200);
       set("max_mana", 6000);
       set("mana", 12000);
       set("mana_factor", 200);
       set("combat_exp", 83000000);
	set("daoxing", 10000000);

       set_skill("literate", 999);
       set_skill("unarmed", 999);
       set_skill("dodge", 999);
       set_skill("parry", 999);
        set_skill("stick", 999);
        set_skill("sword", 999);
        set_skill("liangyi-sword", 999);
        set_skill("spells", 999);
        set_skill("dao", 999);
        set_skill("puti-zhi", 999);
        set_skill("wuxiangforce", 999);
        set_skill("force", 999);
        set_skill("qianjun-bang", 999);
        set_skill("jindouyun", 999);
        map_skill("spells", "dao");
	map_skill("unarmed", "puti-zhi");
	map_skill("force", "wuxiangforce");
	map_skill("stick", "qianjun-bang");
	map_skill("parry", "qianjun-bang");
	map_skill("dodge", "jindouyun");
	map_skill("sword", "liangyi-sword");
	set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
		(: cast_spell, "light" :),
		(: cast_spell, "dingshen" :),
                (: cast_spell, "thunder" :)
        }) );

create_family("方寸山三星洞", 1, "蓝");
setup();

        carry_object("/d/lingtai/obj/pao")->wear();
        carry_object("/d/lingtai/obj/shoe")->wear();
        carry_object("/d/lingtai/obj/putibang")->wield();
}

void attempt_apprentice(object ob)
{	ob=this_player();
	if( (string)ob->query("family/family_name")=="方寸山三星洞") {
	if ((int)ob->query("daoxing") < 2000000 ) {
  	command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才能早悟大道。\n");
	return;
	}
/*
	if( (int)ob->query("pending/kick_out")) {
	command("say 这位" + RANK_D->query_respect(ob) + "反复无常，老夫不原再收你为徒了！\n");
	command("sigh");
	return;
	}
*/
	if ((int)ob->query_int() < 35) {
	command("say 这位" + RANK_D->query_respect(ob) + "悟性太低，恐怕收了你也难有作为！\n");
	command("sigh");
	return;
	}
	if( (int)ob->query_skill("dao", 1) < 200 ) {
	command("say 这位" + RANK_D->query_respect(ob) + "对我道家仙法领会还不够深，现在收你也是勉为其难，不如作罢！\n");
	command("sigh");
	return;
	}
        command("smile");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。");
        command("recruit " + ob->query("id") );
	return;
	}
        command("shake");
        command("say 老夫不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "taoist");
}

int accept_fight(object ob)
{	command("say " + RANK_D->query_rude(ob) + "杀心太重，恐祸不久已！\n");
	return 0;
}
void die()
{

        if( environment() ) {
        message("sound", "\n\n菩提祖师微皱眉头，道：这厮果是个天成地就的！\n\n", environment());
        command("sigh");
        message("sound", "\n菩提祖师身形一转，化做青烟走了。。。\n\n", environment());
        }

        destruct(this_object());
}


