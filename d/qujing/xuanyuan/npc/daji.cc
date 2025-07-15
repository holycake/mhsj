// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("妲几", ({"da ji", "daji", "master"}));
       set("long",
"她就是以自己美色灭了成汤帝业的妲几,据说当年已被\n出斩,后来女娲娘娘开恩将其重召,门下,派其来下界创此轩辕墓.\n");
       set("title", "轩辕墓主人");
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
   //    set("rank_info/respect", "仙姑");
       set("per", 30);
   set("int", 30);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 1400000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 130);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("needle",180);
       set_skill("blade", 180);
       set_skill("spells", 180);
        set_skill("xuanhu-shentong", 160);
        set_skill("fox-hand", 160);
        set_skill("xuanhu-xinfa", 180);
        set_skill("xuanhu-blade", 180);
        set_skill("tianyi-zhen", 160);
        set_skill("huxing-step", 200);
        map_skill("spells", "xuanhu-shentong");
        map_skill("unarmed", "fox-hand");
        map_skill("force", "xuanhu-xinfa");
    //    map_skill("blade", "xuanhu-blade");
        map_skill("needle","tianyi-zhen");
        map_skill("parry", "xuanhu-blade");
        map_skill("dodge", "huxing-step");

create_family("轩辕墓", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/needle/needle1")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们这只收女徒，这位" +
RANK_D->query_respect(ob) + "还是拜别人吧。\n");
           return;}
   if ( (int)ob->query("per") <20){
     command("shake");
   command("say 以我看这位" +
RANK_D->query_respect(ob) + "的资质并不适于跳舞，还是另请高就吧。\n");
   return;
}
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们轩辕墓发扬光大。\n");
        command("recruit " + ob->query("id") );
        return;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "yaomo");
}


