// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
int give_me(object ob);

void create()
{
       set_name("龟八斗", ({"gui badou", "gui"}));

	set("long","海底的大才子，以才智过人著称，并且会画金龙符。\n");
      	set("gender", "男性");
       	set("age", 56);
        set("title", WHT"水晶宫军师"NOR);
        set("per", 10);
        set("max_kee", 1000);
        set("max_sen",1000);
       	set("attitude", "peaceful");
       	set_skill("unarmed",200);
       	set_skill("dodge",200);
        set_skill("parry", 200);
       	set_skill("literate",200);
	set_skill("force", 200);
	set_skill("spells", 200);
        set("combat_exp", 2000000);
  set("daoxing", 500000);

	set("force", 4000);
	set("force_factor",100);
	set("max_force", 2000);
	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 100);
        set("inquiry", ([
                "金龙符": (: give_me :),
                "fu": (: give_me :),
        ]) );


        setup();
        add_money("gold", 1);
       carry_object("/d/gao/obj/magua")->wear();

}

int give_me(object ob)
{
        object who, me;
        who=this_player();
        me=this_object();

        if( (string)who->query("family/family_name")!="东海龙宫" ) {
                message_vision("$N斜斜地瞟了$n一眼，说：此不足为外人道也！\n", me, who);
                return 1;
        }
	if ((int)me->query("number") >= 10)
		return notify_fail("龟八斗把手一伸，今天写太多了，明儿个再说吧！\n");

                ob=new("/d/sea/obj/fu");
                ob->move(who);
		me->add("number",1);

		message_vision("$N拿出张符纸来，画出金龙，递给了$n。\n", me, who);
                return 1;
}

