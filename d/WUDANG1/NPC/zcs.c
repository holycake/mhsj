#include <ansi.h>
inherit NPC;
inherit F_MASTER;
  string ask_chuxian();
     string ask_cancel();

void create()
{
	set_name(HIC"张翠山"NOR, ({ "zhang cuishan", "zhang" }));
	set("nickname", "武当五侠");
	set("long", 
		"他就是张三丰的五弟子张翠山。\n");
	set("gender", "男性");
	set("age", 30);
	set("attitude", "friendly");
	set("shen_type", 1);
	set("str", 26);
	set("int", 30);
	set("con", 26);
	set("spi", 28);
	
	set("mana", 4000);
	set("max_mana", 4000);
	set("force", 4000);
	set("max_force", 4000);
	set("combat_exp", 1139063);
	set("daoxing", 2390000);

	set_skill("force", 180);
	set_skill("wudang-force", 180);
	set_skill("dodge", 180);
	set_skill("tiyunzong", 180);
	set_skill("unarmed", 180);
	set_skill("taiji-quan", 180);
	set_skill("parry", 180);
	set_skill("sword", 180);
	set_skill("taiji-jian", 180);
	set_skill("wudang-spells", 180);
	set_skill("literate", 150);
	set_skill("spells", 180);

	map_skill("spells", "wudang-spells");
	map_skill("force", "wudang-force");
	map_skill("dodge", "tiyunzong");
	map_skill("unarmed", "taiji-quan");
	map_skill("parry", "taiji-jian");
	map_skill("sword", "taiji-jian");

	create_family("武当派", 2, "弟子");
	set("class", "taoist");
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

     if(me->query("family/family_name")!="武当派")
        return ("你不是本门中人!");

     command("pat "+me->query("id"));
     command("say 有志气！");
    return "/d/obj/mieyao"->query_yao(me);
 }
