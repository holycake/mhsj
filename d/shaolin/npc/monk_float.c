// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("和尚", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 20, "弟子");
        set("gender", "男性" );
        set("age",random(20)+ 32);
	set("nickname","棍僧");
        set("long", "这是少林寺的棍僧，专门负责寺内的警卫工作。\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+10000);
        set("attitude", "friendly");
        set_skill("staff", 5+random(100));
	set_skill("xingyi-stick",random(100)+20);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("staff", "xingyi-stick");
        set("chat_chance_combat", 10);
	set("force",100);
        set("chat_msg_combat", ({
                (: perform_action, "staff.powerjam" :),
        }) );
        set("chat_chance", 20);
        set("chat_msg", ({
			"少林和尚说道：不可随便乱走！\n",
			(: random_move :)
        }) );
        set("max_force",100);
	set("force_factor",10);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/stick")->wield();
}

