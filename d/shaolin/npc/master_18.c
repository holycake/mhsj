// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("一尘", ({ "master yi", "master"}) );
        set("nickname", HIM "天龙" NOR);
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
少林第十八代长老，专门传授少林金刚武功。\n"
	);
        create_family("少林寺", 18, "长老");
        set("combat_exp", 1300000);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 130);
	set_skill("unarmed",130);
	set_skill("puti-steps",130);
	set_skill("dabei-strike",130);
	set_skill("buddhism",150);
	set_skill("chanting",130);
	set_skill("xiaochengforce",100);
	set_skill("staff",130);
	set_skill("parry",130);
	set_skill("fumostaff",130);
	set_skill("blade",130);
	set_skill("sword",130);
	set_skill("whip",130);
	set_skill("tianlongwhip",130);
	set_skill("suiyuan-sword",130);
	set_skill("lianxin-blade",130);
	set_skill("xingyi-stick",130);
	map_skill("sword","suiyuan-sword");
	map_skill("staff","xingyi-stick");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

}

void attempt_apprentice(object me)
{
	if(me->query("gender") != "男性")
	{
	command("say 少林金刚只可以是男弟子。。。\n");
	return;
	}
	if(me->query_temp("won_master_di"))
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
                student->set("title","少林寺金刚");
                return ;

}
int accept_fight(object me)
{
        
        command("say 好，你赢了我，你就可以去找少林中更高深的师傅了！\n");
        return 1;
        }
       
void win_enemy(object loser)
{
command("say 阿弥陀佛！徒儿还要努力呀！\n");
}
void lose_enemy(object winner)
{
command("say 阿弥陀佛！你可以去找别的师傅去深造了。\n");
winner->set_temp("won_master_yi",1);
}
int valid_leave(object me, string dir)
{
if(dir == "north" && !me->query_temp("won_master_yi"))
{
message_vision("一股大力将$N推了回来，
一个苍老的声音说道：过了一尘长老这一关，才可以闯木人巷。\n",me);
return notify_fail("");
}
return 1;
}

