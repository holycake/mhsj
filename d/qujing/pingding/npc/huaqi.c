// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("狐阿七大王", ({ "huaqi dawang", "huaqi", "dawang", "wang" }));
  set("title", WHT"压龙洞"NOR);   
  set("long", "一位扭腰摆臀的压龙洞妖王，身上隐隐地发出狐臭。\n");
  set("gender", "男性");
  set("age", 64);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 3400);
  set("max_gin", 3400);
  set("max_sen", 3400);
  set("force", 7000);
  set("max_force", 3500);
  set("force_factor", 160);
  set("max_mana", 3500);
  set("mana", 7000);
  set("mana_factor", 160);
  set("combat_exp", 3650000);
  set("daoxing", 1300000);

  set_skill("spells", 370);
  set_skill("dao", 370);
  set_skill("unarmed", 375);
  set_skill("puti-zhi", 375);
  set_skill("dodge", 360);
  set_skill("jindouyun", 360);
  set_skill("parry", 365);
  set_skill("force", 360);
  set_skill("wuxiangforce", 360);
  map_skill("spells", "dao");
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  setup();
  carry_object("/d/obj/cloth/shoupipifeng")->wear();
  if ("/d/qujing/pingding/obj/shengreal"->in_mud())
    carry_object("/d/qujing/pingding/obj/shengfake");
  else
    carry_object("/d/qujing/pingding/obj/shengreal");
}

void destruct_me (object me)
{
  destruct (me);
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/pingding_huaqi_killed",1);
    call_out ("taishang_appearing",1,ob);
  }
  message_vision ("\n$N翻倒在地现了真身，是一只狐狸精。\n",me);
  message_vision ("狐狸精死了。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}

void taishang_appearing (object who)
{
  object taishang = new ("/d/qujing/pingding/npc/taishang");

  taishang->announce_success (who);
  destruct (taishang); 
}

void unconcious ()
{
  die ();
}

int accept_fight(object ob)
{
  ob->apply_condition("killer", 100);
  kill_ob(ob);
  return 1;
}

void kill_ob (object ob)
{
  object me = this_object();

  set_temp("my_killer",ob);
  call_out ("hurting",random(5)+5,me,ob);  
  ::kill_ob(ob);
}

void hurting (object me, object ob)
{
  object fabao = present ("fabao",me);

  if (fabao)
    fabao->ji_ob (ob);

  remove_call_out ("hurting");  
  call_out ("hurting",random(10)+10,me,ob);  
}

