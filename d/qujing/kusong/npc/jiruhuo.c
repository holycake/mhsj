// by gslxz@mhsj 2001/11/21 (优化)
// jiruhuo.c
#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
  set_name("急如火", ({"jiru huo","huo"}));
  set("gender", "男性");
  set("age", 10);
  set("title", RED"火云洞健将"NOR);
  set("long","一个贼眉鼠眼的小妖精。\n");
  set("combat_exp", 900000+random(3000));
  set("daoxing", 300000);

  set("per", 15);

  set_skill("dodge", 160);
  set_skill("parry", 160);
  set_skill("unarmed", 160);
  set_skill("force", 160);
  set_skill("spells", 160);
  set_skill("pingtian-dafa", 140);
  set_skill("huomoforce", 140);
  set_skill("moyun-shou", 140);
  set_skill("moshenbu", 140);
  set_skill("spear", 160);
  set_skill("stick", 160);
   set_skill("dali-bang",160);
  map_skill("force", "huomoforce");
  map_skill("spells", "pingtian-dafa");
  map_skill("unarmed", "moyun-shou");
  map_skill("dodge", "moshenbu");

  set("max_sen",1200);
  set("max_kee",1200);

  set("force", 2000);
  set("max_force", 1000);
  set("force_factor", 50);
  set("mana", 2000);
  set("max_mana", 1000);
  set("mana_factor", 50);

        set("inquiry", ([
                "下山": (: expell_me :),
                "leave": (: expell_me :),
]) );

  create_family("火云洞", 3, "蓝");

  setup();

  carry_object("/d/qujing/kusong/obj/tongjia")->wear();
}

void attempt_apprentice(object ob)
{       ob=this_player();

        if( (string)ob->query("family/family_name") == "火云洞") {
		command("say 大家同门中人，不敢当，不敢当！\n");
		return;
	}
                command("grin");
                command("recruit " + ob->query("id"));
	 message("shout", WHT "〖"HIC"门派消息"NOR+WHT"〗："+ WHT"枯松涧火云洞又多了一个弟子"+YEL""+this_player()->name()+WHT"枯松涧火云洞的势力加强了。\n"NOR,users());
    return ;
}

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ) {
                ob->set("class", "yaomo");
                ob->set("title", RED"枯松涧火云洞小妖"NOR);
        }
}

string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="火云洞") {
                me->set_temp("betray", 1);
                return ("既是要出山，却需受山规惩罚，你可愿意(agree)?");
        }
        return ("不知。");
}
void init()
{
::init();
        add_action("do_agree", "agree");
}

int do_agree(string arg)
{
      if(this_player()->query_temp("betray") &&
                  this_player()->query("family/family_name")=="火云洞") {
                message_vision("$N答道：愿意。\n\n", this_player());
                this_player()->add("betray/count", 1);
                this_player()->add("betray/huoyun", 1);
		this_player()->set("combat_exp", this_player()->query("combat_exp")*95/100);
                this_player()->delete("family");
                this_player()->delete("class");
                this_player()->set("title", "普通百姓");
                this_player()->save();
                command("say 那你去吧！\n");
                return 1;
                }
        return 0;
}


