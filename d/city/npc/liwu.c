// liwu.c

#include <ansi.h>
inherit NPC;

void create()
{
	int skill;

	set_name(HIC "礼物人" NOR, ({ "man" }) );
	set("gender", "男性" );
	set("age", 18+random(10));
	set("long",  "你看到一位先生正在从他的bag里拿礼物，但不知送给谁？\n");
        set("title",HIW "全套装备" NOR);
            set("class", "scholar");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
//        carry_object("/clone/qinghong")->wield();
            carry_object("/clone/yinjia")->wear();
       carry_object("/clone/shoupipifeng");
       carry_object("/clone/tiekui");
       carry_object("/clone/cloudyshoe");
       carry_object("/clone/jiasha");
       carry_object("/clone/dun");
            carry_object("/clone/bi")->wear();
       add_money("gold", 20);
}
