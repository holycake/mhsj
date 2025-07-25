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
        set("long", "这是少林寺专门研究各派武功，寻找破解各派绝招的和尚．\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000000)+100000);
        set("attitude", "friendly");
        set_skill("staff", 5+random(100));
	set_skill("xingyi-stick",random(100)+20);
	set_skill("move",400);
	set_skill("force",200);
	map_skill("staff", "xingyi-stick");
	set("force",100);
        set("max_force",100);
	set("force_factor",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"叹道：难哪！这［天地人魔连环八式］真是毫无破绽！\n",
                name()+"笑道：也不知这李玉函，柳无眉夫妇如何在江湖
立足！这黄山派武功一招中有不下十个破绽！\n",
                name()+"道：这七仙女阵也不过如此！\n",
		name()+"叫道：终于被我找出破绽了！\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

