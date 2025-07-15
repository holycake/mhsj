// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("心鉴", ({ "master jian", "jian"}) );
        set("gender", "男性" );
        set("age",62);
	create_family("少林寺", 17, "长老");
        set("long", "少林寺七大高手之一。\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(600000)+600000);
        set("attitude", "friendly");
        set_skill("yiyangzhi", 70+random(100));
	set_skill("unarmed", 100);
	set_skill("dodge",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：藏经阁丢书，老夫自愿在此面壁十年。\n",
        }) );
	set_skill("move",80);
	set_skill("force",200);
	map_skill("unarmed", "yiyangzhi");
        set("chat_chance_combat", 10);
	set("force",5000);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.qiankun" :),
        }) );
        set("max_force",5000);
	set("force_factor",55);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}
void init()
{
	command("say 你来有什么事吗？\n");
	call_out("do_kick",2+random(3),this_player());
}
int do_kick(object me)
{
object room;
if(me && environment(me) == environment() && !me->is_fighting())
{
		command("say 没有事你可以走了。。\n");
		message_vision("$N袍袖一挥，一股大力将$n送出屋外。\n",this_object(),me);
		room = 	load_object("/d/shaolin/liuzu");
		if(room) me->move(room);
                message_vision("$N从西边的屋子中飞了出来，重重的摔在地下！\n",me);
		me->receive_damage("kee",50);
}
return 1;
}

