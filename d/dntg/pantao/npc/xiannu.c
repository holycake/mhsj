#include <ansi.h>
inherit NPC;

void greeting(object);
void die();
void unconcious();
void announce(object);

void create()
{
  set_name("仙女", ({ "xian nu", "xian"}) );
  set("gender", "女性" );
  set("age", 18);
  set("str", 30);
  set("per", 30);
  set("int", 30);
  set("attitude", "friendly");
  
    set("combat_exp", 500000);
  set("daoxing", 300000);



  set_skill("force",  150); 
  set_skill("spells", 150); 
  set_skill("unarmed",150);
  set_skill("blade",  150);
  set_skill("dodge",  150);
  set_skill("parry",  150);
  set_skill("moonshentong", random(50)+150);
  set_skill("moonforce", 150);
  set_skill("jueqingbian",  random(50)+150);
  set_skill("baihua-zhang",random(50)+150);
  map_skill("force", "moonforce");
  map_skill("spells", "moonshentong");
  map_skill("whip", "jueqingbian");
  map_skill("unarmed","baihua-zhang");

  set("max_kee", 1500);
  set("eff_kee", 1500);
  set("kee", 1500);
  set("max_sen", 1500);
  set("eff_sen", 1500);
  set("sen", 1500);
  set("force", 1600);
  set("max_force", 1600);
  set("mana", 4000);
  set("max_mana", 4000);
  set("force_factor", 100);

  set("chat_chance_combat", 30);
  set("chat_msg_combat", ({
   (: cast_spell, "mihun" :),
  }) );

  setup();

  carry_object("/d/obj/cloth/xianyi")->wear();
  carry_object("/d/obj/weapon/whip/wuchou.c")->wield();
}

void init()
{
  object ob;

  ::init();
  //add_action("do_set","sett");
   if( interactive(ob = this_player()) && !is_fighting() )
   {
       remove_call_out("greeting");
      call_out("greeting", 1, ob);
   }

}

// int do_set() { set_temp("my_killer",this_player());return 1; }

void greeting(object ob)
{
  object me=this_object();
  
  if (ob->query("dntg/pantao")=="doing") {
     command("bow "+ob->query("id"));
     command("say 我奉王母之命，来摘蟠桃，打扰之处，请多包涵。");
  } else command ("shysmile "+ob->query("id"));
  


}
void unconcious() {die();}

void die()
{
  object me = this_object();
  object ob=me->query_temp("my_killer"); 
  int mark;

  if (objectp(ob)) {
    mark=ob->query_temp("pantao/"+me->query("name"));
    //message_vision("好好好！\n",me);
    command("sob "+ob->query("id"));
    message_vision("$N一跺脚，怒道：“你这"+
       RANK_D->query_rude(ob)+
       "，偷吃仙桃还要行凶，待我禀明王母，再来拿你！”\n",
       me);
    message_vision(HIY"$N手一指，召来一朵云彩，高高兴兴地坐了上去，
再吹一声口哨，随之往上冉冉地升起。。。\n"NOR,me);
    if (!mark) {
        ob->set_temp("pantao/"+me->query("name"),1);
        mark=(int) ob->query_temp("pantao/total");
        if (mark) mark++;
        else mark=1;
        ob->set_temp("pantao/total",mark);
        if (mark==7) announce(ob);
    }
    destruct(me);

  }
  else ::die();
  return;
}

void kill_ob (object ob)
{
  object me = this_object();

  if (ob!=me->query_temp("my_killer") )
      me->delete_temp("my_killer");
  ::kill_ob(ob);
}

void announce(object ob) {
   object me=this_object();

   if (ob->query("dntg/pantao") != "doing") return;
   me->set("name","西王母");
   me->set("id","xi wangmu");
   command("chat "+ob->query("name")+"这"+RANK_D->query_rude(ob)+
            "胆大包天，监守自盗，偷吃蟠桃，气杀老身了！");
   ob->set("dntg/pantao","done");
log_file("dntg",sprintf("%s(%s) passed pantao-yuan on %s\n",ob->name(1), geteuid(ob), ctime(time()) ) );
}
 
int accept_object(object me, object ob)
{

     if ((string)ob->query("name")!="桃核") {
            command("shysmile "+me->query("id"));
            command("thank "+me->query("id"));
            //command("give " + ob->query("id") + "to " + me->query("id"));
            destruct(ob);
            return 1;
       }
      if (me->query("dntg/pantao")!="doing") {
             command("trip "+me->query("id"));
             command("boring "+me->query("id"));
             return 1;
       }
       command("ah "+me->query("id"));
       command("say 大胆"+RANK_D->query_rude(me)+
                "竟敢偷吃蟠桃，拿命来！");
       set_temp("my_killer",me);
       kill_ob(me);                  
       return 1;
}      


