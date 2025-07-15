inherit NPC;
#include <ansi.h>

void create()
{
 set_name(HIR"吸血蝙蝠"NOR, ({ "xixue bianfu","bianfu" }) );
 set("gender", "雄性");
 set("age", 1500);
 set("long","这是一个专吸人血的蝙蝠！\n");
 set("str", 48);
 set("cor", 52);
 set("cps", 22);
 set("max_kee", 15000);
 set("max_gin", 10000);
 set("max_sen", 10000);
 set("force",2500);
 set("max_force",2500);
 set("mana",2500);
 set("max_mana",2500);
 set("force_factor",50);
 set_skill("parry",150);
 set_skill("dodge",170);
 set_skill("ghost-steps",170);
 set_skill("unarmed",200);
 set_skill("jinghun-zhang",200);
 map_skill("unarmed","jinghun-zhang");
 map_skill("parry","jinghun-zhang");
 map_skill("dodge","ghost-steps");
 set("attitude", "aggressive");
 set("combat_exp", 2000000+random(2000000));
 setup();
 carry_object("/obj/money/gold")->set_amount(20);
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

void die(object ob,object zhu)
{
        
      if ("/d/obj/baowu/tulingzhu"->in_mud())
        zhu = new("/d/obj/baowu/zhenzhu");              
      else
        zhu = new("/d/obj/baowu/tulingzhu");
        ob = query_temp("my_killer");        
        message_vision(HIB"$N恨恨地道：本大爷今天没时间陪你玩，此宝物暂且让你保管！\n"NOR,this_object());
        message_vision(HIB"$N化成一片黑雾，一溜烟的飞走了。\n"NOR,this_object());
        zhu->move(ob);
        destruct(this_object());
}