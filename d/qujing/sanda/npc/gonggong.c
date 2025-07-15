//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// created 11/5/1997 by snowcat
#include <ansi.h>

inherit NPC;

void create()
{
  set_name("老公公", ({"gong gong", "gong"}));
  set("gender", "男性");
  set("age", 80);
  set("con", 20);
  set("cor", 20);
  set("int", 20);
  set("per", 30);
  set("attitude", "peaceful");
  set("combat_exp", 400000);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jinghun-zhang", 50);
  map_skill("unarmed", "jinghun-zhang");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  set("max_gin", 700);
  set("max_kee", 700);
  set("max_sen", 700);
  set("force", 800);
  set("max_force", 800);
  set("mana", 800);
  set("max_mana", 800);
  set("force_factor", 60);
  set("mana_factor", 60);
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  carry_object("/d/qujing/baoxiang/obj/longtou");
}

void init()
{
  object me = this_object();
  object who = this_player();
  object where = environment(me);

  ::init();

    remove_call_out ("greeting");
    call_out ("greeting",1,me,who);
}

void greeting (object me, object who)
{
  if (me->is_fighting())
    return;

  if (! who ||
      environment(who) != environment(me))
  return;

  message_vision ("$N对$n说道：唉唉，可见吾小女老妻？\n",me,who);
}

void unconcious()
{
  die();
}

void die ()
{
  object me = this_object();
  object ob = query_temp("my_killer");
  object corpse;

  if (ob)
  {
    ob->set_temp("obstacle/sanda_gonggong_killed",1);
    call_out ("pusa_appearing",1,ob);
  }
  message_vision ("\n$N翻倒在地上，死了，现出一堆白骨。\n",me);
  corpse = CHAR_D->make_corpse(me,ob);
  corpse->move(environment(me));
  load_object("/obj/empty");
  me->move("/obj/empty");
  call_out ("destruct_me",3,me);
}


void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
}
void pusa_appearing (object who)
{
  object pusa = new ("/d/qujing/sanda/npc/pusa");

  pusa->announce_success (who);
  destruct (pusa); 
}
void destruct_me (object me)
{
  destruct (me);
}

/*
void check()
{
  object ob = this_player();
  object rulai;
  int i;
  if(! ob->query("obstacle/wuzhuang") )
    return;
 if (ob->query("combat_exp") < 10000)

    return;
  if (ob->query("obstacle/sanda") == "done")

    return;
  if (! ob->query_temp("kill_girl")||!ob->query_temp("kill_woman") ||
      ! ob->query_temp("man_kill") )
    return;
  i = random(500);
  ob->add("obstacle/number",1);
  ob->set("obstacle/sanda","done");
  ob->add("combat_exp",i+2000);

  rulai = load_object("/d/qujing/lingshan/npc/rulai");

  CHANNEL_D->do_channel(rulai,"chat",ob->query("name")+"慧眼识妖精！");
  message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+ob->query("name")+"闯过西行取经[1;37m第六关！\n"NOR,users());
  tell_object (ob,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  ob->save();
  remove_call_out("des");
  call_out("destruct",1);
  return;
}*/


