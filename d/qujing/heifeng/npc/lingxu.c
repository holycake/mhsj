// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
          set_name("凌虚子", ({"lingxu zi", "zi"}));
          set("gender", "男性");
          set("age", 30);
        set("long", "一个身高臂长的道士，容貌还看的过去。
可仔细一瞧，颈中竟长着密密麻麻的长毛。\n");
          set("attitude", "heroism");
   set("class", "yaomo");
   set("bellicosity", 800);
          set("per", 18);
   set("looking", "相貌凶恶，满脸横肉。");
   set("str", 25);
          set("combat_exp", 2200000);
          set("daoxing",1000000);
        set_skill("unarmed", 275);
        set_skill("dodge", 275);
        set_skill("blade", 275);
        set_skill("parry", 275);
   set_skill("force", 275);
   set_skill("spells", 275);
   set_skill("moshenbu", 275);
   set_skill("cuixin-zhang", 275);
   map_skill("unarmed", "cuixin-zhang");
   map_skill("parry", "cuixin-zhang");
   map_skill("dodge", "moshenbu");
        set("force", 4000);
        set("max_force", 2000);
        set("force_factor", 100);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("max_mana", 2000);
        set("mana", 4000);
   set("mana_factor", 100);
   set("eff_dx", -50000);
   set("nkgain", 300);
   set_temp("apply/armor", 25);
   setup();
   carry_object("/d/obj/cloth/changpao")->wear();
   carry_object("/d/qujing/jisaiguo/obj/panzi");
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
  call_out ("move_to_cave",1,this_object());
}

void move_to_cave (object me)
{
  object where = environment(me);
  object room = load_object("/d/qujing/heifeng/cave");
  if (! where ||
    where->query("short") == "洞内")
    return;

  message_vision ("\n$N驾云夺路而逃！\n",me);
  me->move(room);
}


