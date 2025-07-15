// hanfei.c
//By gslxz@mhsj 2001/6/1


#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIG"绿林悍匪"NOR,({ "lulin hanfei","fei" }) );
	set("title",HIY"无恶不作"NOR);
        set("gender", "男性" );
        set("age", 33);
        set("long", 
"这是无恶不作的绿林悍匪，经常到处杀人。\n");

	set("int", 30);
	set("str", 25);
	set("con", 25);
	set("dex", 25);
        set("attitude", "aggressive");
        set("shen_type", -1);
 set("shen_type", 1);
        set("per", 35);
        set("int", 30);
       set("max_kee", 1300);
       set("max_gin", 1300);
       set("max_sen", 1300);
       set("force", 2100);
       set("max_force", 2100);
       set("force_factor", 100);
       set("max_mana", 2100);
       set("mana", 2100);
 set("mana_factor", 100);
       set("combat_exp", 2568300);
  set("daoxing", 2730000);

	set_skill("unarmed",290);
	set_skill("stealing",300);
	set_skill("force", 290);
	set_skill("dodge", 290);
	set_skill("parry", 290);
	set_skill("sword", 200);
	set_skill("staff", 200);
	set_skill("literate", 280);
	set_skill("huaying-spells", 260);
	set_skill("xiaoyaoyou",280);
	set_skill("spells", 290);
	set_skill("moyun-shou", 280);
	set_skill("yihua-force", 290);
	set_skill("feihua-sword", 290);

	map_skill("spells", "huaying-spells");
	map_skill("force", "yihua-force");
	map_skill("unarmed", "moyun-shou");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "feihua-sword");
	map_skill("sword", "feihua-sword");
	
        set("chat_chance", 60);
//        set("chat_msg", ({
//                (: random_move :),
//        }) );

        setup();
        carry_object( __DIR__ "changjian")->wield();
        carry_object( __DIR__ "lingzhi");
	add_money("gold",1);

}
void self_dest(object me)
{
    if(!me) return;
    if(!environment(me)) return;
    tell_object(environment(me),name()+
	    "大叫一声：我去也。\n");
    destruct(me);
}
void init()
{object ob;

	set_heart_beat(1);
	::init();if( interactive(ob = this_player()) ) {
		remove_call_out("tou");
		call_out("tou",1, ob);
}
    call_out("self_dest",1+random(600),this_object());
    remove_call_out("announce");
    call_out("announce",random(10),this_player());
	}


void tou(object ob)
{
	switch( random(2) ) {
		case 0:
                //       command("get gold from this_player()");
                       command("look " + ob->query("id"));
                       command("follow " + ob->query("id"));
                       command ("grin");
                             break;

		case 1:
                        command("get gold from this_player()");
                                           command("look " + ob->query("id"));
                       command("follow " + ob->query("id"));
                       command ("grin");
                       break;
	}
}

