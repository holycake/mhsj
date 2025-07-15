//Cracked by Roath
// xiaohong.c 小红
// by yfeng

#include <ansi.h>

inherit NPC;
int give_tea();

void create()
{
	set_name(HIM"小红"NOR, ({"xiao hong","ya huan","yahuan" }));
	set("long", 
"她是武馆里端茶送水的小姑娘，水灵灵的大眼睛，
看起来活泼可爱，听说几年前由于家乡水灾，与
亲人失散，幸好遇到馆主好心收留了她，虽然是
一个端茶送水的小丫鬟，但馆主待她却像女儿一
样。\n"
		);
	set("gender", "女性");
	set("age", 16);
	set("per",27);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	set("inquiry",([
		"tea":		(:give_tea:),
		"cha":		(:give_tea:),
		"乌龙茶":	(:give_tea:),
		"洞顶乌龙":	(:give_tea:)]));

	setup();
	carry_object(__DIR__"obj/cuihongcloth")->wear();
}

int give_tea()
{
	object ob=this_player();
	
	return JOB_OB("wuguan")->job_asktea(ob);
}
