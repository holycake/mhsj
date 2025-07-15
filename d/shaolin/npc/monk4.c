// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
	string *name = ({"单","明","西","容","普","渡","影","呵","青","回","云","兰"});
        set_name("地"+name[random(sizeof(name))], ({ "shaolin monk", "monk"}) );
        set("gender", "男性" );
        set("age",random(20)+ 32);
	create_family("少林寺", 19, "弟子");
        set("long", "这是少林寺的和尚\n");
	set("vendetta_mark","shaolin");
        set("combat_exp", random(100000)+100000);
        set("attitude", "friendly");
        set_skill("blade", 60+random(100));
	set_skill("lianxin-blade",random(100)+150);
	set_skill("dodge",100);
        set("chat_chance", 2);
        set("chat_msg", ({
                name()+"说道：听说昨天又有人从木人巷打下山去了！\n",
        }) );
	set_skill("move",80);
	set_skill("force",200);
	map_skill("blade", "lianxin-blade");
        set("chat_chance_combat", 10);
	set("force",500);
        set("chat_msg_combat", ({
		name()+"笑道：在少林寺大门前撒野！\n",
                (: perform_action, "blade.yipianlianxin" :),
        }) );
        set("max_force",500);
	set("force_factor",15);
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
	carry_object(__DIR__"obj/jiblade")->wield();
}

int accept_object(object who, object ob)
{
                if( (int)ob->value() == 50000 ) {
                        say( name()+"掂了掂手中的"+ob->name()+"，笑道：啊？？．．哈哈哈．．\n");
			say( name()+"顺手将"+ob->name()+"揣入了怀中。\n");
                        who->set_temp("shaolin", 1);
                        return 1;
                } else {
			command("shake");
                        return 0;
                }
        return 0;
} 

