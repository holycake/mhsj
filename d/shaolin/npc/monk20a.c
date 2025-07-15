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
        set("long", "这是少林寺的棍僧。\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+10000);
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
                name()+"头一偏，整个人差点睡倒在地上。\n",
                name()+"神色端庄，口中振振有辞。\n",
                name()+"双眼微闭，嘴唇微动。。。\n",
		name()+"全身就像一块石头一样，一动不动。\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

