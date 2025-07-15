inherit NPC;

void create()
{
	set_name("仆人", ({ "pu ren", "pu", "ren" }));
	set("long",
		"绝情谷的仆人，负责一般的杂务。\n");
	set("gender", "男性");
	set("age", 28);
	set("attitude", "friendly");
	set("shen", -1000);
	set("str", 25);
	set("int", 24);
	set("con", 28);
    set("dex", 26);
set("max_kee", 600);
        set("max_sen", 800);
        set("force", 1200);
        set("max_force", 800);
        set("enforce_actor", 10);
        set("combat_exp", 100000);
         set_skill("force", 80);
         set_skill("dodge", 80);
         set_skill("parry", 80);
         set_skill("unarmed", 80);
         set_skill("sword", 80);
        setup();
//        carry_object("/d/obj/weapon/sword/di")->wield();
        carry_object("/u/fly/obj/wcloth")->wear();
}
