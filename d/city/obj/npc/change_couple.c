#include <ansi.h>
#include <command.h>
inherit NPC;

//modify by fly 
//2000-12-2

int accept_object(object me, object ob);
string change(object me);

void create()
{
        set_name("霍大先生",({ "guan jia","guanjia","huo","xiansheng" }));
        set("gender", "男性" );
        set("per", 10);
        set("age", 23);
    set("title", HIW"知府管家"NOR);
        set("long",
HIC"既是开封府管家,又是开封府帐房
凡是有能赚钱的事情,他都肯做的,嘿嘿。\n"NOR);
        set("combat_exp", 2000000);
        set("attitude", "friendly");
        set("inquiry", ([
            "婚姻": (: change :),
            "老婆":  "老婆没了就找,只要有钱,什么不成,爱情...你相信吗?",
            "妻子":  "妻子没了就找,只要有钱,什么不成,爱情...你相信吗?",
            "丈夫":  "丈夫没了就找,只要有钱,什么不成,爱情...你相信吗?",
        ]) );
        setup();
}

string change(object me)
{
   int p,i;
        me = this_player();
 if ( me->query("couple/change_ask"))
        {
      command("? "+me->query("id"));
            return HIB"问过也就吧了，你不觉得你很罗嗦！\n"NOR;
         }
 if (!me->query("married")){
      command("xbc97 "+me->query("id"));
      command("hmm "+me->query("id"));
      command("say 你还是未婚者，来这里问啥呢？");   
      return HIB"去去，快去，去......\n"NOR; 
      }
 if (!me->query("marks/couple_times"))
        {
      command("xbc97 "+me->query("id"));
      if ((string)me->query("gender") == "女性")         
            command("say 丈夫没了，的确很可怜.....！！");
      else command("say 妻子没了，的确很可怜.....！！");
      command("poor");    
      message_vision(HIY"帐房说了偷偷地摆了摆手,便宜一点，只要"NOR+HIR" 100 "NOR+HIB"gold才行\n"NOR,me);       
       me->set("couple/change_ask",1);
       return HIB"不过，还是先交了钱在说了！\n"NOR;
          }
      i=(int)me->query("marks/couple_times");
      p=i*i*i*100+100;
      command("xbc97 "+me->query("id"));
      command("grin "+me->query("id"));
      if ((string)me->query("gender") == "女性")         
            command("say 你怎么和这么多男人.......！！");
      else command("say 你怎么和这么多女人.....！！");
      command("say 但不过有钱就行.这次就这个数字吧");
      message_vision(HIY"帐房说了偷偷地摆了摆手,啊，得要"NOR+HIR+p+NOR+HIB"gold才行\n"NOR,me);
       me->set("couple/change_ask",1);
       return HIB"不过，还是先交了钱在说了！\n"NOR;
}

int accept_object(object me, object ob)
{
    int i,p;
    i=(int)me->query("marks/couple_times");
    p=i*i;
    if (!me->query("couple/change_ask"))
    {
      command("?");
      return notify_fail(HIB"没理由给我钱干吗?嘿嘿！！\n"NOR);
    }
    if(ob->query("money_id") && ob->value() >= (p*1000000+1000000))
    {
        command("nod");
        command("say 好吧，"+me->query("name")+"你等等我来查查！\n"NOR);
      if ((string)me->query("gender") == "女性")         
            command("say 你原来的丈夫是"+me->query("couple/name")+",听说自杀了？");
      else  command("say 你原来的妻子是"+me->query("couple/name")+",听说自杀了？");
        me->delete("couple/change_ask");
        me->set("couple/change_test",1);
        call_out("do_test", 5, me);
        return 1;
        }
       else {
        command("heng");
        command("say 嘿嘿，"+me->query("name")+"你倒大胆，来人把他打出去！\n");
        me->delete_temp("couple/change_ask");
        me->move("/d/kaifeng/tieta");
      message_vision(HIB"$N浑身伤痕地被打了出来。\n"NOR,me);
        return 1;
        }
}

string do_test(object me)
{      
       object ob;
       ob=new(LOGIN_OB);
       ob->set("id",me->query("couple/name"));
       if(!ob->restore() && me->query("couple/change_test")){
          command("look " + me->query("id"));
          command("poor " + me->query("id"));
          command("say 看起来事情不没错的。");
          command("say 我就给你改了这段姻缘吧"); 
      if ((string)me->query("gender") == "男性")         
       {
            message("channel:chat",HIW"\n【大唐天朝】"NOR+HIM"知府管家"NOR+WHT"(Guan Jia)"NOR+MAG"："NOR+me->query("name")+HIC"原来的妻子"NOR+me->query("couple/name")+HIC"已经自杀，本官查明属实。\n"NOR,users());
            message("channel:chat",HIW"【大唐天朝】"NOR+HIM"知府管家"NOR+WHT"(Guan Jia)"NOR+MAG"："NOR+me->query("name")+HIC"现在特许为单身，特此登记。\n"NOR,users());
        }
        else {    message("channel:chat",HIW"\n【大唐天朝】"NOR+HIM"知府管家"NOR+WHT"(Guan Jia)"NOR+MAG"："NOR+me->query("name")+HIC"原来的丈夫"NOR+me->query("couple/name")+HIC"已经自杀，本官查明属实。\n"NOR,users());
            message("channel:chat",HIW"【大唐天朝】"NOR+HIM"知府管家"NOR+WHT"(Guan Jia)"NOR+MAG"："NOR+me->query("name")+HIC"现在特许为独身，特此登记。\n"NOR,users());
        }
    if (!me->query("marks/couple_times"))
        me->set("marks/couple_times",1);
      else me->add("marks/couple_times",1);
          me->delete("couple/change_test");
          me->delete("married");
          me->delete("couple");
          me->delete("husband");
          me->delete("wife");   
          return HIB"一切是缘，你可以走了！\n"NOR; 
         } 
          command("look " + me->query("id"));
          command("? " + me->query("id"));
          command("say 我看事情不是这么简单的。");
          command("say 这段姻缘我改不了。"); 
          me->delete("couple/change_test");
          me->delete("couple/change_ask");
          return HIB"你可以走了！,不过，钱却没了的。\n"NOR;
} 
