inherit NPC;

void create()
{
       set_name("鳅婆", ({"qiupo"}));

set("long","一位老婆婆，是龙女的贴身仆人．\n");
       set("gender", "女性");
       set("age", 56);
	set("per", 20);
       set("attitude", "peaceful");
       set("shen_type", 1);
	set_skill("unarmed", 50);
	set_skill("dodge", 80);
	set_skill("parry", 40);
        set("combat_exp", 26000);
  set("daoxing", 50000);

        setup();
        add_money("silver", 1);
//        carry_object("/d/gao/obj/blade")->wield();

}

