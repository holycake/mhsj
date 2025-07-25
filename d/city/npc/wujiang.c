// wujiang.c 武将

inherit NPC;

#include "greeting.h"

void create()
{
        set_name("守城武将", ({ "wu jiang", "wu", "jiang" }));
        set("gender", "男性");
        set("age", random(10) + 30);
        set("str", 25);
        set("long", "他威风凛凛，杀气腾腾，虽然只是个守城门的小官，当年也是打过大仗的。\n");
        set("combat_exp", 80000);
        set("attitude", "peaceful");

        set_skill("unarmed", 70);
        set_skill("force", 70);
        set_skill("sword", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
	set("max_kee", 700);
	set("max_sen", 600);
        set("force", 400); 
        set("max_force", 400);
        set("force_factor", 15);
	set("max_mana", 100);
	set("mana", 100);
	set("mana_factor", 5);
        setup();
        carry_object("/d/obj/weapon/sword/changjian")->wield();
        carry_object("/d/obj/armor/tiejia")->wear();
}

void init()
{
        object ob;
        ::init();
        if (interactive(ob = this_player()) && 
                (int)ob->query_condition("killer")) {
//                remove_call_out("kill_ob");
//                call_out("kill_ob", 1, ob);
        }
        greeting2(this_player());
}
int accept_fight(object me)
{
        message_vision("守城武将对$N把眼一瞪，喝道：呔，大胆，还不退下！\n\n", me);
        return 0;
}

