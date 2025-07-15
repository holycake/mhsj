

#include <ansi.h>

inherit NPC;



void create()
{
	set_name("宠物饲养员", ({ "siyang yuan", "yuan" }) );
	set("title", HIY"宠物店老板"NOR);
	set("gender", "男性" );

	set("age", 50);
	set("str", 30);
	set("con", 30);
	set("dex", 25);
	set("int", 25);
         
	set("long",
		"他是这个饲养店的老板，不过好象是没有请到帮手，所以自己就又当老板又当伙计。\n" );

	set("combat_exp", 50000);
	set("attitude", "friendly");
	

	set("qi", 1000);
	set("max_qi", 1000);
	set("jing", 500);
	set("max_jing", 500);
	set("neili", 1000);
	set("max_neili", 1000);
        set("jiali",50);

        set_skill("unarmed",70);
        set_skill("dodge",70);
        set_skill("parry",70);
        set_skill("force",70);
 
        set_temp("apply/attack",50);
        set_temp("apply/defense",50);




	setup();
    carry_object("/d/liwu/obj/weiqun")->wear();
	
	
}

void init()
{
	object ob;

	::init();

	if( interactive(ob=this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting",1,ob);
	}
}


void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return;

      command("say 你是来领宠物的吧？\n");
}

