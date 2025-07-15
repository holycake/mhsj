#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_chuxian();
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
  set("combat_exp", 2000000);
  set("daoxing", 2000000);

  set("max_kee", 1500);
  set("max_sen", 1500);
  set("max_mana", 3200);
  set("mana", 3200);
  set("max_force", 3200);
  set("force", 3200);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 230);
    set_skill("tianpeng-force", 230);
  set_skill("dodge", 250);
  set_skill("parry", 230);
  set_skill("rake", 230);
  set_skill("force", 230);
  set_skill("spells", 230);
  set_skill("xbuddhism", 230);
  set_skill("yanxing-steps", 230);
  set_skill("skyriver-rake", 250);
  set_skill("sougu-zhua", 230);
  map_skill("unarmed", "sougu-zhua");
    map_skill("force", "tianpeng-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
   create_family("天蓬府", 2, "弟子");
         set("inquiry", ([
     "除恶" : (:ask_chuxian:),
   "cancel": (:ask_cancel:),
    ]));
    
            setup();

            carry_object("/d/wudang1/obj/tiejian")->wield();
	carry_object("/d/wudang1/obj/whiterobe")->wear();
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
void attempt_apprentice(object ob)
{
	if ( (string)ob->query("family/family_name")=="武当派") {
		if ((int)ob->query_skill("wudang-force", 1) < 150) {
		command("say 我武当派乃内家武功，最重视内功心法。"); 
		command("say " + RANK_D->query_respect(ob) + 
			"是否还应该在武当心法上多下点功夫？");
		return;
	}
	if (((int)ob->query("daoxing") < 300000 )) {
	command("say 我们修真之士最重的就是道行，" + RANK_D->query_respect(ob) + "还需多加努力才是。\n");
	return;
	}
        command("smile");
	command("say 好极，好极，时下妖魔当道，鬼怪横行。象"  + RANK_D->query_respect(ob) +
"这样的正义之士却是少见！\n");
        command("say 很好，" + RANK_D->query_respect(ob) + "多加努力，他日必定有成。\n");
       command("recruit " + ob->query("id") );
	return;
	}
	command("shake");
	command("say 本人不收外门弟子，" + RANK_D->query_respect(ob) + "还是另寻他人吧！\n");
        return;
}
int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) ){
                ob->set("class", "taoist");
}
        return 0;
}

string ask_chuxian()
{
    object me=this_player();

    if((string)me->query("family/family_name")=="天蓬府") {
      command("smile "+me->query("id"));
      return "/d/obj/mieyao"->query_yao(me);
    }
    return ("非我门人,何故来此?\n");
}
