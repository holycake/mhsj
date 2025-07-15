// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
   set_name("妇人", ({ "woman", "fu ren"}));
   set("gender", "女性" );
   set("age", 45);
   set("per",40);
   set("long","一位不施脂粉犹美，风流还似少年才的美妇。\n");
   set("combat_exp", 600+random(400));
   set("daoxing", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/d/qujing/dudi/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

void init()
{
        object ob = this_player();
        add_action("do_yes","yes");
	remove_call_out("checking");
        call_out("checking",1,ob);
}

void checking(object ob)
{	object me = this_object();
        if( ob->query("obstacle/village") == "done" )
                return;
        if( !ob->query("obstacle/liusha") )
                return;

        if( ob->query_temp("yao_killed") <3 
          && ob->query_temp("seen") )
                {
	message_vision(CYN"$N对$n苦苦的哀求道：去帮我杀了那些妖怪吧。好吗？\n"NOR,me,ob);
        return;
                }
        if( ob->query_temp("yao_killed") 
        && ! ob->query_temp("cao_given") )
          {
        message_vision(CYN"$N对$n说道：这位"+RANK_D->query_respect(ob)+"能否再帮我去寻找"+RED"七叶琼芝草"NOR+CYN"？\n"NOR,me,ob);
        return;
          }
        message_vision(CYN"$N对着$n说道：听说这位"+RANK_D->query_respect(ob)+"是去西天取真经的，能否(yes)帮个忙呢？\n"NOR,me,ob);
        
        ob->set_temp("womenask","yes");
        return;
}
int do_yes()
{	object ob=this_object();
	object me=this_player();
	if( me->query_temp("womenask")=="yes")
	{
	message_vision(CYN"$N对着$n点点头道：愿为效劳。\n"NOR,me,ob);
	call_out("give_task",1+random(2),me,ob);
	return 1;
	}
	return 0;
}
	
int give_task(object me,object ob)
{
	tell_object(me,CYN"妇人对你说道：我们家北面有些妖怪在作乱，不知你能否帮我杀了他们啊？\n"NOR);
	me->delete_temp("womenask");
	me->set_temp("seen",1);
	return 1;
}


int accept_object(object who,object ob)
{
      

         if( ob->name() == RED "七叶琼芝草" NOR )
                {
                if( !who->query_temp("yao_killed") )
                  {
                command("say 你还是先去帮我杀了那些妖怪吧。好吗？");
                return 0;
                  }
                command("smile");
                command("nod");
                who->set_temp("cao_given",1);
                this_object()->set_name("骊山老母",({"lishan laomu","lao mu"}));
                call_out("pass",1,this_player());
                return 1;
                }
        return 0;
}

void pass(object ob)
{
  int i;
 if( ! ob->query_temp("yao_killed") )
     return;
  if(! ob->query("obstacle/liusha") )
  return;
 if (ob->query("combat_exp") < 10000)
    return;
  if (ob->query("obstacle/village") == "done")
    return;
  i = random(500);
  ob->add("obstacle/number",1);
  ob->set("obstacle/village","done");
       ob->add("daoxing",i+2000);
  command("chat "+ob->query("name")+"经住耐心与勇气的考验！");
  message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+ob->name()+"闯过西行取经[1;37m第八关！\n"NOR,users());
  tell_object (ob,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  ob->delete("seen");
  ob->save();
  destruct(this_object());
  return;
}
