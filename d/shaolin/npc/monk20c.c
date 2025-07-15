// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("老僧", ({ "shaolin monk", "monk"}) );
        create_family("少林寺", 17, "弟子");
        set("gender", "男性" );
        set("age",random(30)+ 62);
	set("nickname","兼通数艺");
        set("long", "这是少林寺专门研究各派武功，寻找破解各派绝招的和尚．\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(1000000)+1000000);
        set("attitude", "friendly");
        set_skill("unarmed", 200+random(100));
	set_skill("move",400);
	set_skill("force",200);
	set("force",100);
        set("max_force",100);
	set("force_factor",10);
        set("chat_chance", 10);
        set("chat_msg", ({
                name()+"叹道：又是秋天了吗？\n",
                name()+"笑道：你想看这里的秘笈？\n",
                name()+"道：给你看也没有用，你的天赋不够！\n",
		name()+"道：老衲已经二十余载没有下楼一步了！\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

