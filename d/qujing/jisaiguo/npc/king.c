inherit NPC;

void create()
{
       set_name("祭赛国国王", ({"jisai guowang", "guowang", "king"}));
       set("gender", "男性");
       set("age", 30);
        set("long", "祭赛国国王，看起来英明神武的样子。\n");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("per", 25);
	set("str", 25);
       set("combat_exp", 15000);
  set("daoxing", 30000);

        set_skill("unarmed", 75);
        set_skill("dodge", 75);
        set_skill("blade", 75);
        set_skill("parry", 75);
	set_skill("force", 75);
        set("force", 700);
        set("max_force", 700);
        set("force_factor", 10);
        set("max_kee", 800);
        set("max_sen", 800);
        set("max_mana", 30);
        set("mana", 30);
setup();
	carry_object("/d/obj/cloth/longpao")->wear();
}


int accept_object(object me,object ob)
{       object who;
	me=this_object();
        who=this_player();

        if (ob->query("id")=="shu tie" ){
	if(who->query("obstacle/jisaiguo")=="done") {
		command("say "+RANK_D->query_respect(who)+ "已替朕取回了佛宝，真是辛苦了！\n");
		call_out("destroy", 1, ob);
		return 1;
	}	
	if(who->query("obstacle/jisaiguo")=="allow") {
			command("say " +RANK_D->query_respect(who)+ "还没起身吗？\n");
                call_out("destroy", 1, ob);
                return 1;
	}	
	if( who->query_temp("obstacle/jisaiguo/letter")) {
		command("say 原来如此，看来朕错怪了金光寺的僧人了。\n");
		command("say " +RANK_D->query_respect(who)+
"满身的好武艺，不如替朕把佛宝取回，造福百姓。\n");
		who->set("obstacle/jisaiguo", "allow");
                call_out("destroy", 1, ob);
                return 1;
        }
	command("say 朕已知道了，不劳"+RANK_D->query_respect(who)+ "操心了！\n");
        call_out("destroy", 1, ob);
	return 1;
	}

	if(ob->query("id")=="tooth") {
		if( !ob->query("asdfghj") ){
			command("say 什么东西，朕不要它！\n");
			return 0;
			}
		if( who->query("obstacle/jisaiguo")=="done") {
			command("say 又劳" +RANK_D->query_respect(who)+ "了，祝一路顺风。\n");
			call_out("destroy", 1, ob);
			return 1;
			}
		call_out("announce_success", 3, me, who);
		call_out("destroy", 1, ob);
		return 1;
	}
	return 0;
}
void destroy(object ob)
{
        destruct(ob);
        return;
}
void announce_success(object me,object who)
{//disabled announce and reward...
    int i;
  who->add("obstacle/number",1);
  who->set("obstacle/jisaiguo","done");
  who->delete_temp("obstacle/jisaiguo");
  i = random(800);
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"替朕取回佛宝舍利子，为祭赛百性造福，真侠义心肠也！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第二十三关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}


