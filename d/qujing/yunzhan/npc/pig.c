// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("猪怪", ({ "zhu guai","pig" }));
  set("age", 600);
  set("gender", "男性");
  set("long", "一个野猪怪。\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
  set("combat_exp",3500000);
  set("daoxing",2500000);
  set("max_kee", 3000);
  set("max_sen", 3000);
  set("max_force", 6000);
  set("force", 3000);
  set("force_factor", 100);
  set("mana_factor", 100);
  set_skill("unarmed", 290);
  set_skill("dodge", 260);
  set_skill("parry", 260);
  set_skill("rake", 350);
  set_skill("force", 280);
  set_skill("spells", 280);
  set_skill("baguazhou", 280);
  set_skill("yanxing-steps", 270);
  set_skill("skyriver-rake", 380);
  map_skill("force", "lengquan-force");
  map_skill("spells", "baguazhou");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  setup();
  carry_object("/d/kaifeng/obj/jiuchipa")->wield();
  carry_object("/d/obj/armor/tongjia")->wear();
}
void init()
{
          object ob = this_player();

        if ( ob->query_temp("apply/name")&&
            ob->query_temp("apply/name")[0] == "翠兰" )
        {
        command("hug cui lan");
        command("kiss cui lan");
        return;
        }
        return ;
}

int accept_fight (object ob)
{
  ob->apply_condition ("killer",100);
  kill_ob (ob);
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
//  string place;
  //place = "/d/qujing/yunzhan/shulin1";
 // place[strlen(place)-1] = '0'+random(10); 
  if (! where ||
    where->query("short") == "[33m树林[m")
    return;
  message_vision ("\n$N化作一道金光消失了！\n",me);
  me->move("/d/qujing/yunzhan/shulin7");
}
void die()
{
  object me = this_object();
  object ob = query_temp("my_killer");

  if (ob)
  {
  message_vision(HIR"只见$N变成道道金光直冲云霄。\n"NOR,me);
  message_vision(HIR"原来$N是个天官下凡，投错了胎。\n"NOR,me);
  ob->set_temp("pig_killed",1);
  destruct(me) ;
   }
}
