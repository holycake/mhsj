// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("国王", ({"guo wang", "wang", "king"}));
  set("long", "头戴一顶冲天冠，腰束一条碧玉带，身穿一领飞龙舞凤赭黄袍。\n");
  set("title", WHT"乌鸡国"NOR);
  set("gender", "男性");
  set("age", 46);
  set("per", 30);
  set("attitude", "peaceful");
  set("shen_type", 1);
  set("combat_exp", 4300000);
  set("daoxing", 2500000);

  set("max_kee", 3000);
  set("max_gin", 3000);
  set("max_sen", 3000);
  set("force", 6000);
  set("max_force", 3000);
  set("force_factor", 150);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 130);
  set_skill("unarmed", 370);
  set_skill("dodge", 370);
  set_skill("force", 370);
  set_skill("parry", 370);
  set_skill("fork", 370);
  set_skill("spells", 370);
  set_skill("seashentong", 370);
  set_skill("dragonfight", 370);
  set_skill("dragonforce", 370);
  set_skill("fengbo-cha", 370);
  set_skill("dragonstep", 370);
  map_skill("spells", "seashentong");
  map_skill("unarmed", "dragonfight");
  map_skill("force", "dragonforce");
  map_skill("fork", "fengbo-cha");
  map_skill("parry", "fengbo-cha");
  map_skill("dodge", "dragonstep");
  set("eff_dx",-30000);
  set("nkgain",180);

  setup();
  carry_object("/d/obj/cloth/longpao")->wear();
}

void autokill (object me)
{ 
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  if (me->is_fighting())
    return;

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  message_vision ("$N对$n大喝一声：“妖怪魔头，竟敢欺世盗名变做朕的模样！”\n",
                  me,king2);
  message_vision ("$N与$n立刻撕打了起来！\n",me,king2);
  me->kill_ob(king2);
  king2->kill_ob(me);
}

void init ()
{
  autokill (this_object());  
}

void die ()
{
  object me = this_object ();
  object longpao = present("long pao",me);
  object where = environment (me);
  object king1 = present ("guo wang 1",where);
  object king2 = present ("guo wang 2",where);

  message_vision ("$N发出一声长长的哀鸣，在尘土里现了青毛狮子的原身！\n",me);
  message_vision ("\n青毛狮子瞪着琉璃盏红眼，喘着粗气。\n",me);
  me->set_name("青毛狮子", ({"blue lion", "lion"}));
  me->delete("title");
  me->delete("long");
  if (longpao)
    destruct (longpao);  
  me->setup();
  me->remove_all_killer();
  me->set("gin",3000);
  me->set("kee",3000);
  me->set("sen",3000);
  call_out("destruct_me",5,me);

  if (! king2)
    return;

  if (king2 == me)
    king2 = king1;

  king2->announce_success();
}

void destruct_me (object me)
{
  message_vision ("一道金光照住$N，将$N唰地一声收去。\n",me);
  message_vision ("天上远远传来文殊菩萨的笑声。\n",me);
 
  destruct (me);   
}
