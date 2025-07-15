inherit NPC;
#include <ansi.h>

void create()
{
  set_name("猪八戒", ({ "zhu bajie", "zhu", "bajie" }));
  set("age", 70);
  set("title", HIY"天蓬元帅"NOR);
    set("gender", "男性");
  set("long", "嘿嘿，连老猪都不认识啦？\n");
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 10);
       set("class", "xian");
  set("combat_exp", 12000000);
  set("daoxing", 8000000);

  set("max_kee", 3000);
  set("max_sen", 3000);
  set("max_force", 6300);
  set("force", 12600);
  set("max_mana", 6300);
  set("mana", 12600);
  set("force_factor", 150);
  set("mana_factor", 150);
  set_skill("unarmed", 500);
  set_skill("dodge", 500);
  set_skill("parry", 500);
  set_skill("rake", 500);
  set_skill("force", 500);
  set_skill("spells", 500);
  set_skill("xbuddhism", 500);
  set_skill("yanxing-steps", 500);
  set_skill("skyriver-rake", 500);
  set_skill("sougu-zhua", 500);
  map_skill("unarmed", "sougu-zhua");
  map_skill("force", "lengquan-force");
  map_skill("spells", "xbuddhism");
  map_skill("rake", "skyriver-rake");
  map_skill("parry", "skyriver-rake");
  map_skill("dodge", "yanxing-steps");
  set("chat_chance",5);
  set("chat_msg",({
    "猪八戒乐呵呵地说道：谁能给俺老猪去找点吃的东西来。\n",
    "猪八戒想想说：乡下发大水灾了，老猪该当救济饥民。\n",
    "猪八戒说道：老猪要寻遍天下美酒佳肴，再请世人来俺帅府品尝品尝。\n",
    "猪八戒说道：不是老猪贪嘴，俺老猪想凑个美宴，请平民百姓也能尝个新鲜。\n",
    "猪八戒自言自语地说：俺老猪不是为自己，老猪想收集世上美食，让大唐人都能来尝尝。\n",
    "猪八戒扭过身去捧起澡盆大的金饭盆吧嗒吧嗒大嚼了起来。\n",
    "猪八戒弯腰捧起水桶大的银酒壶咕咚咕咚地灌了下去。\n",
  }));
  set("inquiry", ([
        "here":   "此乃天蓬帅府也，老猪西天归来后唐太宗御赐在此开府，专事饮食慈善业。\n",
        "name":   "猪八戒，谁人不知也。\n",
     ]));
   create_family("天蓬府", 1, "蓝");
  setup();
  carry_object("/d/tianpeng/obj/tianpengpa")->wield();
  carry_object("/clone/armor/jinjia")->wear();
}
void init ()
{
  call_out ("check_player",1,this_player());
}

void attempt_apprentice(object ob)
{
             if (((int)ob->query("daoxing") < 3000000 )) {
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
                ob->set("per","11");
}




