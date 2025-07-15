//ground.c

#include <ansi.h>
inherit ROOM;
#include "/d/kaifeng/ground.h"


void create()
{
  set ("short",HIG "[" HIR "擂台" HIG "]" NOR);
  set ("long",@LONG
  
           八  仙  过  海         各  显  神  通

LONG);
  // set("no_flee",1);
  set("no_quit",1);
  set("broadcast",1);
  set("alternative_die",1);
  set("exits",([ ]));
  setup();
}
  
void alternative_die (object me)
{
  object ob = me->query_temp("last_damage_from");
  if (me->query("kee")<0) me->set("kee",10);
  if (me->query("eff_kee")<0) me->set("eff_kee",10);
  me->remove_killer(ob);
  ob->remove_killer(me);
  message_vision(HIG"$n把$N打翻在地，飞起一脚，将$N踢下了擂台。\n"NOR,me,ob);
  message_vision(HIG"$n在观众的欢呼声中，高高兴兴地下场休息了。\n"NOR,me,ob);
  tell_room( __DIR__"under","\n>\n");
  me->move(__DIR__"under");
  ob->move(__DIR__"under");
   me->set("kee",(int)me->query_temp("statusbef/kee"));
   me->set("eff_kee",(int)me->query_temp("statusbef/eff_kee"));
   me->set("sen",(int)me->query_temp("statusbef/sen"));
   me->set("eff_sen",(int)me->query_temp("statusbef/eff_sen"));
   me->set("force",(int)me->query_temp("statusbef/force"));
   me->set("mana",(int)me->query_temp("statusbef/mana"));
   ob->set("kee",(int)ob->query_temp("statusbef/kee"));
   ob->set("eff_kee",(int)ob->query_temp("statusbef/eff_kee"));
   ob->set("eff_sen",(int)ob->query_temp("statusbef/eff_sen"));
   ob->set("sen",(int)ob->query_temp("statusbef/sen"));
   ob->set("force",(int)ob->query_temp("statusbef/force"));
   ob->set("mana",(int)ob->query_temp("statusbef/mana"));
}

void broadcast(string str)
{
  string prefix = HIY"〖擂台〗"NOR;
  string s1 = str, s2 = "";
  while (strsrch(s1,"\n\n") != -1)
    s1 = replace_string(s1,"\n\n","\n");

  if (s1[strlen(s1)-1]=='\n')
  {
    s1 = s1[0..strlen(s1)-2];
    s2 = "\n";
  }
  if (strlen(s1) == 0)
    return;
  s1 = replace_string(s1,"\n","\n"+prefix)+"";
  reset_eval_cost();
  tell_room( __DIR__"under","\n"+prefix+s1 );
}
