//change.c
inherit NPC;
inherit F_MASTER;

void create()
{
       set_name("茗烟",({"ming yan","fairy", "girl"}));
       set("long",
"其珠翠之辉辉兮，满额鹅黄。出没花间兮，宜嗔宜喜；徘徊池上兮，
若飞若扬。蛾眉颦笑兮，将言而未语；莲步乍移兮，欲止而欲行。\n");
       set("title", "月宫伺女");
       set("gender", "女性");
       set("age", 18);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
	set("int", 30);
       set("max_kee", 800);
       set("max_gin", 600);
       set("max_sen", 600);
       set("force", 600);
       set("max_force", 600);
       set("force_factor", 40);
       set("max_mana", 500);
       set("mana", 500);
       set("mana_factor", 40);
       set("combat_exp", 100000);
  set("daoxing", 50000);

       set_skill("literate", 80);
       set_skill("unarmed", 80);
       set_skill("dodge", 100);
       set_skill("force", 80);
       set_skill("parry", 80);
       set_skill("sword", 80);
       set_skill("spells", 80);

create_family("月宫", 3, "弟子");
setup();

        carry_object("/d/obj/cloth/luoyi")->wear();
}


