// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("虚寒", ({ "master xu", "master"}) );
        set("nickname", HIR "莲心" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 67);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林第二十代长老，专门传授少林入室弟子武功。\n"
	);
        create_family("少林寺", 21, "长老");
        set("combat_exp", 700000);
        set_skill("move", 100);
        set_skill("dodge", 100);
        set_skill("force", 100);
        set_skill("literate", 100);
	set_skill("unarmed",100);
	set_skill("puti-steps",100);
	set_skill("dabei-strike",100);
	set_skill("buddhism",120);
	set_skill("chanting",100);
	set_skill("xiaochengforce",50);
	set_skill("staff",100);
	set_skill("parry",100);
	set_skill("fumostaff",100);
	set_skill("blade",100);
	set_skill("lianxin-blade",100);
	map_skill("staff","fumostaff");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/jiblade")->wield();

}

void attempt_apprentice(object me)
{
	if(me->query("gender") != "男性")
	{
	command("say 少林入室弟子只可以是男弟子。。。\n");
	return;
	}
	if(me->query_temp("won_master_yuan"))
	{
	command("smile");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("shake");
	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
}
void re_rank(object student)
{
                student->set("title","少林寺入室弟子");
                return ;

}
int accept_fight(object me)
{
        if(me->query("family/family_name") == query("family/family_name") &&
	   me->query("family/master_id") == query("id"))
        {
        command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        return 1;
        }
        else
        {
        command("say 阿弥陀佛！贫僧武功低微，施主不要开这种玩笑。\n");
        return 0;
        }
}
void win_enemy(object loser)
{
command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
winner->set_temp("won_master_xu",1);
}
