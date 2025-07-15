// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("心眉", ({ "master mei", "master"}) );
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 64);
	set("per", 35);
	set("agi",30);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林寺七大高手之一。
\n"
	);
        create_family("少林寺", 17, "大师");
        set("combat_exp", 4000000);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 130);
	set_skill("axe",130);
	set_skill("puti-steps",130);
	set_skill("wuche-axe",130);
	set_skill("buddhism",130);
	set_skill("chanting",130);
	set_skill("xiaochengforce",130);
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("axe", "wuche-axe");
        set("chat_chance_combat", 5);
        set("chat_msg_combat", ({
                (: perform_action, "axe.sanbanfu" :)
        }) );
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/axe")->wield();

}

void attempt_apprentice(object me)
{
	if(me->query_temp("won_master_yi"))
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
                student->set("title","少林寺长老");
                return ;
}
