// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
       set_name("师师", ({"shishi"}));
       set("long",
"她乃是轩辕古墓中派出来收徒的小狐仙.\n");
       set("title",HIG"丽妖"NOR );
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 30);
   set("int", 30);
       set("max_kee", 500);
       set("max_gin", 500);
       set("max_sen", 500);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 200000);

        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 20);
       set_skill("unarmed", 70);
       set_skill("dodge", 80);
       set_skill("tianyi-zhen",80);
       set_skill("force", 80);
       set_skill("xuanhu-shentong", 75);
       set_skill("xuanhu-xinfa",80);
       set_skill("fox-hand",70);
       set_skill("huxing-step",80);
       set_skill("parry", 90);
       set_skill("spells", 90);
       map_skill("dodge","huxing-step");
       map_skill("force","xianhu-xianfa");
       map_skill("unarmed","tianyi-zhen");
       map_skill("parry","fox-hand");
       map_skill("spells","xuanhu-shentong");


create_family("轩辕古墓", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
       carry_object("/d/moon/obj/snow_sword")->wield();
}

void attempt_apprentice(object ob)
{
        if ( !((string)ob->query("gender")=="女性")){
           command("shake");
           command("say 我们这只收女徒，这位" +
RANK_D->query_respect(ob) + "还是另请高就吧。\n");
           return;
        }

        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们古墓发扬光大。\n");
        command("recruit " + ob->query("id") );
        return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "huli");
}
