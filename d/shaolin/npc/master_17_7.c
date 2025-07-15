
// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void getting();
int kill_him();
void create()
{
        set_name("心鉴", ({ "master jian", "master"}) );
        set("gender", "男性" );
        set("age", 44);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
\n"
	);
        create_family("少林寺", 17, "长老");
        set("combat_exp", 900000);
        set_skill("move", 90);
        set_skill("dodge", 90);
        set_skill("force", 90);
        set_skill("literate", 90);
	set_skill("unarmed",90);
	set_skill("puti-steps",90);
	set_skill("dabei-strike",90);
	set_skill("buddhism",110);
	set_skill("chanting",90);
	set_skill("dachengforce",90);
	set_skill("staff",90);
	set_skill("parry",90);
	set_skill("fumostaff",90);
	map_skill("staff","fumostaff");
	map_skill("parry","fumostaff");
        map_skill("dodge", "puti-steps");
	map_skill("force", "dachengforce");
	map_skill("unarmed", "dabei-strike");
    set("chat_chance", 15);
    set("chat_msg", ({
		"神秘的人物左翻翻右翻翻．．．根本不把你放在眼里！\n",
		"神秘的人物用手敲了敲经书盒．．\n",
            (: getting :)

    }) );
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
            (: getting :)

        }) );
        setup();
        carry_object(__DIR__"obj/skinmask")->wear();

}
void hide()
{
	object *inv;
	int i;
        if( !environment() ) return;
	inv = all_inventory(environment());
	for(i=0;i<sizeof(inv);i++)
	if(inv[i]->query("family/family_name") == "少林寺")
		inv[i]->set("marks/lost_jing_shu",1);	
	message_vision("$N阴笑一声：＂丢了经书，等着被逐出师门吧！\n",this_object());
	message_vision("$N一越，跳出窗口不见了．．．\n",this_object());
        call_out("disappear", 1);
}

void disappear()
{
        destruct(this_object());
}

void getting()
{
command("get jingshuhe");
call_out("hide",10+random(20));
}
void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
	{
        killer->set("marks/protect_jing_shu", 1);
        if(!killer->query("m_success/勇保经书"))
        {
                killer->set("m_success/勇保经书",1);
                killer->add("score",700);
        }
	}
        ::die();

}

void unconcious()
{
::die();
}
