// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("心湖", ({ "master hu", "master"}) );
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("chat_chance", 20);
        set("chat_msg", ({
                        name()+"道：经书一丢再丢，谁还肯去守经楼？\n"
        }) );
        set("age", 84);
	set("per", 35);
	set("agi",30);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林寺现任掌门人，由于少林常丢经书，现在喜怒无偿，经常将守经书
的弟子逐出少林。
\n"
	);
        create_family("少林寺", 17, "掌门");
        set("combat_exp", 5000000);
        set_skill("move", 140);
        set_skill("dodge", 140);
        set_skill("force", 140);
        set_skill("literate", 140);
	set_skill("fanwen",100);
set_skill("unarmed",140);
	set_skill("puti-steps",140);
	set_skill("dabei-strike",140);
	set_skill("buddhism",160);
	set_skill("chanting",140);
	set_skill("xiaochengforce",140);
	set_skill("yiyangzhi",140);
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "yiyangzhi");
        set("inquiry", ([
"守经楼": "你想去看守藏经楼？....嗯....丢了经书可是要被逐出少林的，你不怕吗？（answer）\n",
        ]) );
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/staff")->wield();

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
void init()
{
add_action("do_answer","answer");

}
int do_answer(string arg)
{
	object ob;
if(arg == "不怕" ) {
command("say 好，你去吧！\n");
command("say 这里是我的手谕，你用（wave）它才可以上藏经楼。\n");
ob = new(__DIR__"obj/shouyu");
if(ob) ob->move(this_player());
return 1;
}
return 0;
}
