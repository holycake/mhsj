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
                name()+"舞动长棍，全身毫无破绽，扬起一溜尘土。\n",
                name()+"一不小心，差点从梅花桩上掉下来！\n",
                name()+"拿起一块青砖猛然向自己的前额回去。。。青砖应声而裂！\n",
		name()+"将手中八十斤的大刀耍得象一朵花儿似的。\n"
        }) );
	setup();
	carry_object(__DIR__"obj/monk_cloth")->wear();
}

