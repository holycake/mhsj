// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("鹿力大仙", ({"luli daxian", "luli", "daxian" }));
  set("title","国师");
  set("long","车迟国的三大道士之一，善于求水祈雨，被尊为国师。\n");
  set("gender", "男性");
  set("rank_info/respect", "国师");
  set("age", 40);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("per", 30);
  set("int", 30);
  set("max_kee", 1300);
  set("max_gin", 1300);
  set("max_sen", 1300);
  set("force", 1300);
  set("max_force", 1300);
  set("force_factor", 80);
  set("max_mana", 1300);
  set("mana", 1300);
  set("mana_factor", 40);
  set("combat_exp", 900000);
  set("daoxing", 1000000);

  set_skill("unarmed", 75);
  set_skill("dodge", 75);
  set_skill("parry", 75);
  set_skill("spells", 75);
  set_skill("force", 75);
  set_skill("wuxiangforce", 75);
  set_skill("dao", 75);
  set_skill("jindouyun", 75);
  set_skill("puti-zhi", 75);
  map_skill("unarmed", "puti-zhi");
  map_skill("dodge", "jindouyun");
  map_skill("force", "wuxiangforce");
  map_skill("spells", "dao");
  set("eff_dx",-160000);
  set("nkgain",240);
  
  setup();
  carry_object("/d/obj/cloth/daopao")->wear();
  
}

void init()
{
  ::init();
  call_out("follow_player",random(10)+1,this_object(),this_player());
}

void follow_player (object me, object who)
{
  object room = environment(me);

  if (room->query("short")!="三清殿")
    return;

  if (! who)
    return;

  if (me->query("have_followed"))
    return;
    
  if (who->query("obstacle/chechi")=="done")
    return;

  if (who->query_temp("obstacle/chechi")!="eaten")
    return;

  if (room != environment(who))
    return;

  me->set_temp("no_return",1);
  me->set("have_followed",1);
  message_vision ("只见$N一边祷告，一边斜眼看着$n。\n",me,who);
  who->set("mana",0);

  call_out("do_follow",random(3)+3,me,who);
}

void do_follow (object me, object who)
{
  object room = environment(me);

  if (room->query("short")!="三清殿")
    return;

  if (! who)
    return;

  if (room != environment(who))
    return;

  me->set_leader(who);
  message_vision ("$N对着$n一声冷笑。\n",me,who);
  if (!who->query_temp("chechi/recognized"))
  {
    who->set_temp("chechi/recognized",1);
    message_vision("$N喝道：“大胆顽徒，竟敢冒充我道圣人！快去见国王领罪！”\n",
                   me,who);
  }
  message_vision ("$N决定开始跟随$n一起行动。\n",me,who);
}

void die()
{
  object me = this_object();
  object where = environment(me);
  object ob = new ("/d/qujing/chechi/obj/lutou");

  message_vision ("$N软软地倒下，留下一只白色鹿头。\n",me);
  ob->move(where);
  destruct(me);
}

