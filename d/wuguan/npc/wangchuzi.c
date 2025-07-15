//Cracked by Roath
// wangchuzi.c 王厨子

#include <ansi.h>


inherit NPC;

void destruct_fish(object me,object obj);

void create()
{
	set_name("王厨子", ({ "wang chuzi","wang" }));
	set("long", 
		"他身体肥胖，是武馆里的有名的厨子。\n"
		"虽然，他做的饭菜比不上皇宫里的山珍\n"
		"海味，但在傲来国内却也是有名的。\n"
		);
	set("gender", "男性");
	set("age", 32);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	setup();
	carry_object(__DIR__"obj/qingcloth")->wear();
}

int accept_object(object ob,object obj)
{
	object me=this_object();
	
	return JOB_OB("wuguan")->give_fish(me,ob,obj);
}