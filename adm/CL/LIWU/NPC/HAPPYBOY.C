// happyboy.c 年轻男孩

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("年轻男孩", ({ "happy boy", "boy" }));
	set("age", 18);
	set("gender", "男性");
	set("long", "他和女孩一样，都是欢乐接的特选使者。\n");
	set("attitude", "friendly");
	set("nickname", HIC"欢乐使者"NOR);
	set("shen_type", 1);
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 26);
	set("combat_exp", 5000);
	set("shen_type", 1);

	set_skill("unarmed", 35);
	set_skill("dodge", 35);
	set_skill("parry", 35);
	set_skill("force", 35);
       
        setup();
    carry_object("/d/liwu/obj/jiericloth")->wear();
}

