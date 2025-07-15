//sgzl

inherit NPC;

void create()
{
        set_name("崩将军", ({"beng jiangjun","beng","monkey"}));
        set("title","花果山大将");
        set("gender", "男性" );
        set("age", 35);
        set("class","taoist");
        set("long", "一只成了精的通背猿。\n");
        set("combat_exp", 60000);
  set("daoxing", 30000);

        set("attitude", "peaceful");
        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("spells", 60);

        set("max_kee", 450);
        set("max_gin", 450);
        set("max_sen", 450);

        set("max_force", 600);
        set("force", 600);
        set("force_factor", 30);
	set("max_mana", 400);
	set("mana", 400);
	set("mana_factor", 20);
        setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 3);
        set("inquiry", ([
                "name" : "我就是花果山水帘洞大将崩将军。\n",
                "here" : "这就是花果山。\n", 
                "大王" : "嘿！我家大王就是花果山水帘洞洞主。\n", 
                "weapon" : "我们花果山正缺这玩艺，要能搞点来多好！\n", 
                "bingqi" : "我们花果山正缺这玩艺，要能搞点来多好！\n", 
                "兵器" : "我们花果山正缺这玩艺，要能搞点来多好！\n", 
	 ]) );

        set("chat_msg", ({
	    "崩将军说道：要想守卫我花果山，就须操练兵马。\n",	
            "崩将军自言自语的说：我等须得些锋利剑戟才能抵御来犯之敌。\n",
            "崩将军低头说道：到哪里才能搞些兵器来呢？\n",
        }) );
}

int accept_object(object who, object ob)
{
	object me=this_object();

        if ((string)ob->query("id")!="bing qi") 
          {
           command("say 这玩艺有什么用？");
           message_vision ("\n$N顺手把"+ ob->query("name")+ "扔了。\n",me);
           return 1;
           }
        else if (who->query("dntg/donghai")=="begin" || who->query("dntg/donghai")=="allow" 
            || who->query("dntg/donghai")=="done")
          {
          command("say 兵器已经够用了，不劳大王操心了。\n");
          return 1;
          }
/*
        else if (who->query("dntg/huaguo")!="done")
          {
          message_vision ("\n$N道：＂您不是我们花果山的人，给我这个是什么意思？＂\n",me);
          return 1;
          }
*/
        else if (random(10) != 1)
	  {
          message_vision ("\n$N兴奋的叫道：太好了！要是再多一点儿就更好了。\n",me);
          return 1;
          }
        else 
          {
          command("jump");
          command("say 大王，我们的兵器是够用了，您自己也挑一样称手的家伙吧！\n");
          who->set("dntg/donghai","begin");
          return 1;
          }


}



