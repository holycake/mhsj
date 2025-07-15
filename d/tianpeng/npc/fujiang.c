// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao(object me);
string ask_cancel();
void create()
{
  set_name("猪肥膘", ({ "zhu feibiao", "zhu", "feibiao" }));
  set("age", 35);
  set("title", HIY"天蓬府副将"NOR);
  set("gender", "男性");
  set("long", "他就是天蓬府的副将。\n");
  set("attitude", "peaceful");
       set("class", "xian");
  set("str", 50);
  set("per", 13);
  set("combat_exp", 5000000);
  set("daoxing", 3000000);
  set("max_kee", 2500);
  set("max_sen", 2500);
  set("max_mana", 3600);
  set("mana", 7200);
  set("max_force", 3600);
  set("force", 7200);
  set("force_factor", 550);
  set("mana_factor", 550);
  set_skill("unarmed", 530);
    set_skill("tianpeng-force", 530);
  set_skill("dodge", 550);
  set_skill("parry", 530);
  set_skill("rake", 530);
  set_skill("force", 530);
  set_skill("spells", 530);
  set_skill("xbuddhism", 530);
  set_skill("yanxing-steps", 530);
  set_skill("skyriver-rake", 550);
  set_skill("sougu-zhua", 530);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("天蓬府", 2, "弟子");
         set("inquiry", ([
     "除恶" : (:ask_mieyao:),
   "cancel": (:ask_cancel:),
    ]));
 setup();
  carry_object("/d/tianpeng/obj/gangpa")->wield();
  carry_object("/d/tianpeng/obj/jinjia")->wear();
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
// void rewarding (object who, object ob);
void init ()
{
  call_out ("check_player",1,this_player());
}
void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 1500000 )) {
	command("say " + RANK_D->query_respect(ob) +
                          "的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
	return;
	}
	if ( (string)ob->query("family/family_name")=="天蓬府") {
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们天蓬府发扬光大。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )                                                                                                                                                                                                     
                          ob->set("class", "xian");
                ob->set("per",11);
}
string ask_mieyao(object me)
{
    me=this_player();
     if((string)me->query("family/family_name")=="天蓬府") {
//  if(me->query("faith")<100)
//      return ("你还是先多加修炼为妙。");
    tell_room(environment(me),"镇元大仙念念有词.....\n");
    return "/d/obj/mieyao"->query_yao(me);
}
    return ("非我门人,何故来此?\n");
}

