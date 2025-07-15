// jentleman.c 中年绅士

inherit NPC;

void create()
{
	set_name("中年绅士", ({ "jentle man", "man" }));
	set("age", 32);
	set("gender", "男性");
	set("long", "他是一个十分有风度的中年绅士。他也是到欢乐节来游玩。\n");
	set("attitude", "friendly");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 30);
	set("dex", 24);
	set("combat_exp", 25000);
	set("shen_type", 1);

	set_skill("unarmed",60);
	set_skill("dodge", 60);
	set_skill("parry", 60);
	set_skill("blade", 60);
	set_skill("force", 60);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
     setup();
    carry_object("/d/liwu/obj/jiericloth")->wear();
}
