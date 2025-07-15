inherit NPC;

void create()
{
  set_name("禁军教头", ({"jinjun jiaotou", "jiaotou"}));
  set("title", "傲来国");
  set("gender", "男性");
  set("age", 45);

  set("max_gin", 500);
  set("eff_gin", 500);
  set("gin", 500);
  set("max_kee", 500);
  set("eff_kee", 500);
  set("kee", 500);
  set("max_sen", 500);
  set("eff_sen", 500);
  set("sen", 500);

  set("combat_exp", 35000);
  set("daoxing", 15000);

  set_skill("unarmed", 70);
  set_skill("spear", 70);
  set("force", 500);
  set("force_factor", 40);
  set_skill("dodge", 70);
  set_skill("parry", 70);
  setup();
  set("inquiry", ([
]) );

        carry_object("/d/obj/cloth/bingfu.c")->wear();
        carry_object("/d/obj/weapon/spear/tieqiang.c")->wield();

}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{	
  string *ans=({"比武","看热闹","捣乱","从军", });
  int ans1;



        if( !arg ) return notify_fail("你说什么？\n");
        if (arg=="0"|| arg=="1"|| arg=="2"|| arg=="3") 
           {sscanf(arg,"%d",ans1); arg=ans[ans1];}
        message_vision("$N答道：" + arg + "。\n", this_player());
        if( arg== "看热闹" ) 
          {
          command("consider");
          command("say 看热闹可以，但不准大声喧哗，扰乱训练。\n");
          this_player()->set_temp("donghai", 1);
          } 
        else 
          {
          command("say 你胡说什么？别来捣乱！\n");
          }
        return 1;
}

void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N喊到：＂好啊，你敢到这行凶！看我们怎么收拾你！＂说罢跌跌撞撞勉强爬回演武场。\n",me);
  message_vision ("\n又一个$N走了过来。\n",me);
  ob = new (__DIR__"jiaotou");
  ob->move(where);
  destruct (me);
}

void die ()
{
  unconcious();  
}


