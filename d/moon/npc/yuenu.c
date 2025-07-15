// by gslxz@mhsj 2001/10/24
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
       set_name("月奴", ({"yue nu", "yuenu", "yue","master"}));
       set("long",
"她乃是桂树采天地之精华化成，后拜嫦娥为师．\n");
       set("title", WHT"广寒桂花仙"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
	set("int", 30);
       set("max_kee", 1000);
       set("max_gin", 1000);
       set("max_sen", 1000);
       set("force", 2000);
       set("max_force", 1000);
       set("force_factor", 50);
       set("max_mana", 1000);
       set("mana", 2000);
       set("mana_factor", 50);
       set("combat_exp", 800000);
  set("daoxing", 500000);


        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 120);
       set_skill("unarmed", 150);
       set_skill("dodge", 120);
       set_skill("force", 150);
       set_skill("parry", 150);
       set_skill("sword", 150);
       set_skill("spells", 150);
        set_skill("moonshentong", 160);
        set_skill("baihua-zhang", 160);
        set_skill("moonforce", 160);
        set_skill("snowsword", 160);
        set_skill("moondance", 160);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");

create_family("月宫", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
      //  carry_object("/d/moon/obj/guihuajian")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们月宫只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们月宫发扬光大。\n");
        command("recruit " + ob->query("id") );
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"月宫又多了一个弟子"+YEL""+this_player()->name()+WHT"月宫的势力加强了。\n"NOR,users());
 return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "xian");
}
