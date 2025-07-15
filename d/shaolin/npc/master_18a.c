// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("一铁", ({ "master yi", "master"}) );
        set("nickname", HIM "藏经楼首座" NOR);
        set("vendetta_mark","shaolin");
        set("gender", "男性" );
        set("age", 64);
	set("agi",30);
	set("per", 35);
        set("int",30);
	set("attitude","friendly");
        set("max_force", 1500);
        set("force", 1500);
        set("long",
"
少林藏经楼首座，数十年来未下藏经楼一步\n"
	);
        create_family("少林寺", 18, "长老");
        set("combat_exp", 130000000);
	set_temp("apply/damage",2000);
        set_skill("move", 130);
        set_skill("dodge", 130);
        set_skill("force", 130);
        set_skill("literate", 130);
	set_skill("unarmed",130);
	set_skill("puti-steps",130);
	set_skill("dabei-strike",130);
	set_skill("buddhism",150);
	set_skill("chanting",130);
	set_skill("xiaochengforce",100);
	set_skill("staff",130);
	set_skill("parry",130);
	set_skill("fumostaff",130);
	set_skill("blade",130);
	set_skill("sword",130);
	set_skill("whip",130);
	set_skill("tianlongwhip",130);
	set_skill("suiyuan-sword",130);
	set_skill("lianxin-blade",130);
	set_skill("xingyi-stick",130);
	map_skill("sword","suiyuan-sword");
	map_skill("staff","xingyi-stick");
	map_skill("parry","lianxin-blade");
        map_skill("dodge", "puti-steps");
	map_skill("force", "xiaochengforce");
	map_skill("unarmed", "dabei-strike");
	map_skill("blade","lianxin-blade");
        setup();
        carry_object(__DIR__"obj/monk_cloth")->wear();

}
void init()
{
	add_action("do_say","say");
}
int do_say(string arg)
{
if (!arg || arg != "开饭了！") return 0;
message_vision("$N睁大双眼道：真的！太好了！\n$N双手微微用力，整个人突然不见了！\n",this_object());
destruct(this_object());
return 1;
}
