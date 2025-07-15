// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("嫦娥", ({"chang e", "change", "chang","master"}));
       set("long",
"西王母的大弟子。早年因帮助丈夫盗取西王母之灵药而\n与其师势成水火。后得和解并邀西王母出掌月宫一门。\n");
       set("title", WHT"广寒宫主人"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
	set("int", 30);
       set("max_kee", 2000);
       set("max_gin", 2000);
       set("max_sen", 2000);
       set("force", 7000);
       set("max_force", 3500);
       set("force_factor", 150);
       set("max_mana", 3500);
       set("mana", 7000);
       set("mana_factor", 150);
       set("combat_exp", 3700000);
  set("daoxing", 3800000);


        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 380);
       set_skill("unarmed", 380);
       set_skill("dodge", 380);
       set_skill("force", 380);
       set_skill("parry", 380);
       set_skill("sword", 380);
       set_skill("spells", 380);
        set_skill("moonshentong", 380);
        set_skill("baihua-zhang", 380);
        set_skill("moonforce", 380);
        set_skill("snowsword", 380);
        set_skill("moondance", 300);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("月宫", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/moon/obj/feijian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;}
        if ( (int)ob->query("per") <22){
	  command("shake");
	command("say 以我看这位" +
RANK_D->query_respect(ob) + "的资质并不适于跳舞，还是另请高就吧。\n");
  ob->set_temp("denied_by_chang_e",1);
	return;
}

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}



