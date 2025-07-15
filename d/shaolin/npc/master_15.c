// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("天峰", ({ "master tian", "master"}) );
        set("nickname", HIW "前任方丈" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 94);
	set("per", 25);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林的第十五代掌门，因年事已高，隐居于此。
\n"
	);
        create_family("少林寺", 15, "大师");
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :)
        }) );
        set("chat_chance", 10);
        set("chat_msg", ({
name()+"低声道：你来的正好，一起品味品味这茶吧。。。\n",
name()+"叹道：这茶好香呀。。。\n"
        }) );
        set("combat_exp", 9000000);
        set_skill("move", 90);
        set_skill("dodge", 90);
        set_skill("force", 90);
        set_skill("literate", 90);
	set_skill("unarmed",90);
	set_skill("puti-steps",90);
	set_skill("yiyangzhi",90);
	set_skill("buddhism",110);
	set_skill("chanting",90);
	set_skill("xiaochengforce",90);
	set_skill("staff",90);
	set_skill("parry",90);
	map_skill("parry","fumostaff");
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "yiyangzhi");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();
}

void attempt_apprentice(object me)
{
	command("shake");
	command("say 老衲年事已高，你还是去找掌门吧！\n");
}
