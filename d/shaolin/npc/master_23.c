// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("空慎", ({ "master kong", "master"}) );
        set("nickname", HIG "无为" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林第二十三代的师傅，他专门传授少林男女俗家弟子武功。
\n"
	);
        create_family("少林寺", 23, "长老");
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :)
        }) );
        set("combat_exp", 300000);
        set_skill("move", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
        set_skill("literate", 80);
	set_skill("unarmed",80);
	set_skill("puti-steps",80);
	set_skill("dabei-strike",80);
	set_skill("buddhism",100);
	set_skill("chanting",70);
	set_skill("dachengforce",80);
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "dabei-strike");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();


}

void attempt_apprentice(object me)
{
	if((int)me->query_skill("dabei-strike",1)>=30 && 
(int)me->query_skill("dachengforce",1)>=30 &&
(int)me->query_skill("puti-steps",1)>=30)
	{
	command("smile");
        command("recruit " + me->query("id") );
		return;
	}
	else
	{
	command("smile");
        command("say 拜师要有诚意，你先去学学碑文吧！\n");

	}
}

void recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "shaolin");
}
void re_rank(object student)
{
                student->set("title","少林寺俗家弟子");
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
winner->set_temp("won_master_kong",1);
}
