// By canoe 2001.03.25
#include <ansi.h>
inherit NPC;
object dog() {return query("dog");}
object juling() {return query("juling");}
object yangjian() {return query("yangjian");}
object target() {return query("target");}

int die() {return 1;}
int unconcious() {return 1;}
int valid_killer(object);
void time_up();
void go_home();
int do_jianmian();
void start();
void call_juling();
void call_yangjian();
void retreat();
void create()
{
       set_name("西王母", ({"xi wangmu", "xi", "wangmu","master"}));
       set("long", "西华至妙生伊川，穆王八骑访昆仑。\n");
       set("title", WHT"织女之母"NOR);
       set("gender","女性");
       set("age", 100);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "老太太");
       set("cor", 30);
       set("per", 30);
       set("looking", "面色红润，满脸福态。");
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2000);
       set("force_factor", 125);
       set("max_mana", 2000);
       set("mana", 4000);
       set("mana_factor", 100);
       set("combat_exp", 2000000);
       set_skill("literate", 150);
       set_skill("unarmed", 150);
       set_skill("dodge", 150);
       set_skill("force", 180);
       set_skill("parry", 150);
       set_skill("sword", 150);
       set_skill("spells", 180);
	set_skill("moonshentong", 180);
	set_skill("baihua-zhang", 180);
	set_skill("moonforce", 180);
	set_skill("snowsword", 200);
	set_skill("moondance", 150);
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("sword", "snowsword");
	map_skill("parry", "snowsword");
	map_skill("dodge", "moondance");
	set("chat_chance_combat", 50);
	set("inquiry", ([
		"jianmian" : (: do_jianmian :),
	        "见面" : (: do_jianmian :),
	]) );
        call_out("time_up",600);   
        setup();
      //  carry_object("/d/obj/cloth/tianyi.c")->wear();
      //  carry_object("/d/ourhome/obj/shoes")->wear();
}
int do_jianmian()
{
object me=this_player();
object ob=this_object();
if (!me->query_temp("ask_niulang")) return notify_fail("你说什么我不知道耶？\n");
set("target",me);
start();
return 1;
}
   
void time_up() {
   if (target()) {
     command("say 哈哈！都过了七月七日了，看来他们今年不能见面了！");
     command("say 看来你只有明年再来了！");
     target()->delete_temp("askd_niulang");
   }
   go_home();
}

void heart_beat() {
   object target=target();
       
   set("eff_kee", 2000);
   set("eff_sen", 2000);
   set("kee",2000);
   set("sen",2000);
   set("force",4000);
   set("mana",4000);
   
   if (target && target->is_ghost()) {
      message_vision(HIY"$N哈哈大笑：“这样水平也来讨公道？告诉你拳头大就是天理！”\n"NOR,this_object());
      command("kick corpse");
      go_home();
      return;
   }
   if (!target || environment(this_object())!=environment(target)) {
       message_vision(HIY"$N哈哈大笑：“这样胆量也来和我讨公道？”\n"NOR,this_object());
       command("puke");
       go_home();
       return;
   }
   ::heart_beat();
}

int valid_killer(object killer) {
   object target=target();
   object me=this_object();

   if (target!=killer && environment(me)==environment(target)) {
     command("sneer");
     command("say 倚多取胜？"+target->query("name")+
        "原来也是浪得虚名之辈？！");
     command("bye");
     target->delete_temp("askd_niulang");
     go_home();
     return 0;
   }
   return 1;
}

void kill_ob(object ob) {
  object me=this_object();
  object target=me->query("target");

  if (!target) ::kill_ob(ob);
  if (valid_killer(ob)) ::kill_ob(ob);
}
        
void go_home() {
   object me=this_object();

   message_vision(HIY"$N手一挥，一阵香风之后，$N带着随从驾云而去。\n"NOR,me);          
   remove_call_out("call_juling");
   remove_call_out("call_yangjian");
   remove_call_out("retreat");
   destruct(dog());
   destruct(juling());
   destruct(yangjian());
   destruct(me);
}

void start() {
  object me=this_object();
  object target=target();
  object dog=new(__DIR__"dog");
  object yangjian=new(__DIR__"yangjian");
  object juling=new(__DIR__"juling");

  set("dog",dog);
  set("yangjian",yangjian);
  yangjian->set("master",me);
  set("juling",juling);
  juling->set("master",me);
  dog->move(environment(me));
  yangjian->move(environment(me));
  juling->move(environment(me));
  
  message_vision(HIY"王母说道：反了!反了!我的家事不用你管！”\n"NOR,me);
  message_vision(HIY"王母突然凤颜大怒，勃然变色：“来人，与我拿下这个蟊贼！”\n"NOR,me);
  message_vision(HIY"只见远处飘来一大团乌云，乌云过后巨灵神跳下云端。\n"NOR,me);
  message_vision(HIY"一会儿，一声呼哨，杨戬带着他的哮天犬从云头跳了下来！\n"NOR,me);
  call_out("call_juling",5);
  
}

void call_juling() {
  object me=this_object();
  object juling=me->juling();
  object target=me->target();

  if (!target || !juling) return;
  
  tell_object(target,"王母对你一指，喝道：“巨灵神，拿人！”\n\n");
  message_vision(HIY"$N手一挥，先锋官巨灵神挥舞大斧头向$n砍杀来。\n\n"NOR,me,target);
  message_vision(HIY"$N朗声道：“"+RANK_D->query_rude(target)+
    "，快点投降，没得大爷我污了斧头！”\n"NOR,juling());

  juling->kill_ob(target);
  juling->set("on_job",1);
}

void lose(object loser) {
  object me=this_object();

  command("kick "+loser->query("id"));
  if (loser==juling()) call_out("call_yangjian",5);
  if (loser==yangjian())   call_out("retreat",5);
      
}

void call_yangjian() {

  message_vision(HIY"$N皱了皱眉头，杨戬会意，纵犬杀将过来。\n"NOR,this_object());
  yangjian()->kill_ob(target());
  dog()->kill_ob(target());
  yangjian()->set("on_job",1);

}

void retreat() {
   command("chat 罢了罢了，我天将都奈你不何，你自己想法让他们见面吧。");
   command("grin");
   command("say 天河没有桥了，看他们怎么办！哈哈！");
   go_home();
}

