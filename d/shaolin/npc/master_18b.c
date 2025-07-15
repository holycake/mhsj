// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("一强", ({ "master yi", "master"}) );
        set("nickname", HIM "大法师" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 64);
	set("agi",30);
	set("skill_public",1);
	set("per", 35);
        set("int",3);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林大法师，少林为武林第一名门正派，绝少败类，便都是他的功劳。\n"
	);
        create_family("少林寺", 18, "长老");
        set("combat_exp", 130000000);
	set_skill("daode",130);
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

}
int recognize_apprentice(object ob)
{
        return 1;
}

