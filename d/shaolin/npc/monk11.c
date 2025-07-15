// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("小沙弥", ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",12);
	create_family("少林寺", 23, "弟子");
        set("long", "这是少林寺的和尚\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000)+1000);
        set("attitude", "friendly");
        set_skill("unarmed", 60+random(10));
	set_skill("dabei-strike",random(10)+70);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"掸了掸屋里的尘土．\n",
        }) );
	set_skill("move",40);
	set_skill("force",20);
	map_skill("unarmed", "dabei-strike");
        set("chat_chance_combat", 10);
	set("force",50);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qianshouqianbian" :),
        }) );
        set("max_force",50);
	set("force_factor",2);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/ironfist")->wield();
}

