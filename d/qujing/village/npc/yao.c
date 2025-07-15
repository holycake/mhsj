// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("食人魔", ({ "shiren mo", "yao"}));
   set("gender", "男性" );
   set("age", 35);
   set("long","一个专门吃人的老妖怪。\n");
   set("max_kee",3200);
   set("max_force",3200);
   set("force",6400);
   set("force_factor", 150);
   set("max_mana",6400);
   set("mana",3200);
   set("combat_exp", 3850000);
   set("attitude","aggressive");
   set_skill("unarmed", 330);
   set_skill("wuxing-quan", 330);
   set_skill("dodge", 320);
   set_skill("baguazhen", 330);
   set_skill("parry", 330);
   set_skill("hammer", 320);
   set_skill("kaishan-chui", 320);
   set_skill("force", 330);
   set_skill("zhenyuan-force", 330);
   set_skill("spells",330);
   set_skill("taiyi", 330);
   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("unarmed", "wuxing-quan");
   map_skill("hammer", "kaishan-chui");
   map_skill("dodge", "baguazhen");
   set("chat_chance_combat", 70);
   set("chat_msg_combat", ({
     (: cast_spell, "qiankun" :),
    }) );
   setup();
   carry_object("/obj/cloth")->wear();
   carry_object("/d/qujing/village/obj/hammer")->wield();
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
  return 1;
}

void kill_ob (object ob)
{
  set_temp("no_return",1);
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void die()
{
        object ob=query_temp("my_killer");
	if(ob->query_temp("seen"))
	{       ob->add_temp("yao_killed",1);}
        ::die();
}
