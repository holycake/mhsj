// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("心树", ({ "master shu", "master"}) );
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
        set("combat_exp", 5000000);
        set_skill("move", 200);
        set_skill("dodge", 200);
        set_skill("force", 200);
        set_skill("literate", 200);
	set_skill("buddhism",200);
	set_skill("chanting",200);
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

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
