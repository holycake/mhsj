// baochai.c  薛宝钗
#include <ansi.h>
inherit NPC;
string ask_tea();
string ask_poem();
//string clone_npc();
int singing();
void create()
{
       set_name("薛宝钗", ({ "xue baochai", "xue", "baochai" }) );
       set("title", MAG "不离不弃，芳龄永继" NOR);
       set("gender", "女性" );
       set("shen_type", 1);
       set("age", 17);
       set("str", 20);
       set("con", 40);
       set("int", 50);
       set("dex", 40);
       set("per", 100);
       set("kar", 100);
       set("no_clean_up",1);
       set("long",
HIW"她便是金陵十二钗之一的薛宝钗，
年岁虽不大，然品格端方，
容貌丰美，人多谓天仙所不及。\n"NOR );
       set("combat_exp", 20000);
       set("attitude", "peaceful");
       set("max_qi", 300);
       set("max_jing", 300);
       set("neili", 100);
       set("max_neili", 100);
       set_skill("literate", 500);
       set("inquiry", ([
                   "name" : "小女子薛宝钗。",
                   "here" : "这里就是雪人相公的居所凝香阁。",
                   "fly" : "fly就是我相公啊，你怎么蠢得连这都不知道？",
                   "飞雪" : "飞雪就是这里的主人啊，你怎么蠢得连这都不知道？",
                   "黛玉" : "她是我妹妹。",
                   "林黛玉" : "她是我妹妹。",
                   "回疆" : "你去问我妹妹吧。",
                   "茶" : (: ask_tea :), 
                   "tea" : (: ask_tea :), 
                   "菩提" : "你也知道菩提、明镜？那你请诵一遍《六祖得法偈》吧。", 
                   "明镜" : "你也知道菩提、明镜？那你请诵一遍《六祖得法偈》吧。", 
                   "《六祖得法偈》" : (: ask_poem :), 
                   "六祖得法偈" : (: ask_poem :), 
       ]) );
       setup();
       set("chat_chance", 2);
       set("chat_msg", ({
 "薛宝钗打开扇子，轻轻扇了扇风。\n",
 "薛宝钗眼望窗外，轻声吟道：菩提无树，明镜非台。爱亦有恨，喜即是哀。\n",
 "薛宝钗回过头来，问道：你知道何为菩提、明镜吗？？ \n",
       }) );
       carry_object("/u/fly/obj/jinshan")->wield();
       carry_object("/u/fly/obj/qupu");
       carry_object("/u/fly/obj/pipa");
}
void init()
{
        object ob;
                  ::init();
                  if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
   add_action("do_mo", ({"18mo", "kiss", "hug", "lean", "flirt", "interest"}));
   add_action("do_mo", ({"fire", "kick", "smash", "taste", "hehe", "kiss1"}));
   add_action("do_song","song");
}
void greeting(object ob)
{
        object ball;
        if( !ob || environment(ob) != environment() ) return;
        if((string)ob->query("id")=="fly")
                {
                command("wanfu fly");
                say("薛宝钗轻声问候" + ob->query("name") + "：您累了吧？让我给您捶捶背。\n");
                say("薛宝钗红着脸，为" + ob->query("name") + "轻轻地捶着背。\n");
                if( !objectp(ball = present("xue qiu", ob)) )
                  new("/u/fly/ball")->move(ob);
               }      
        if(ob->query_temp("kill_baochai"))
               {
                message_vision("薛宝钗眉头一皱：这个无理之徒又来了，赶他出去！\n",ob);
                message_vision("只见几个家丁跑进来，把$N乱棒赶了出去。\n",ob);
                ob->move("/d/wiz/wizroom");
                ob->receive_damage("qi", 100);
                message_vision(ob->name() + "被人乱棒打了出来。\n",ob);
        }
        if((string)ob->query("id")!="fly")
                say("薛宝钗道了个万福：这位" + RANK_D->query_respect(ob)
              + "请进，欢迎来凝香阁做客。\n");
}
string ask_poem()
{
        object me;
        me=this_player();
        if(me->query_temp("jie") )
            {
             command("angry");
             return "你不是刚刚解答了吗？\n";
             }
        if((string)me->query("id")=="fly")
             { 
               command("xixi");
               command("lover fly");
               return "你明明知道还问我。\n";
             }
        else {
        command("nod");
        command("say 《六祖得法偈》是最著名的偈，我告诉你前半部，你诵(song)出余下部分吧。\n");
        me->set_temp("jie", 1);
        return "菩提本无树，明镜亦非台\n";
        }
}
int do_song(string arg)
{
     object me = this_player();
      if( !arg ) return 0;
      if( !me->query_temp("jie") ) return 0;
      if(arg == "本来无一物，何处惹尘埃" || arg == "本来无一物，何处有尘埃。") {
                message_vision(CYN"$N诵道：" + arg +"\n"NOR,this_player());
                command("sigh " + me->query("id"));
                command("say 你那是契嵩与宗宝本的 《六祖得法偈》，流传虽广，却有违慧能禅师的本意。\n");
                command("shake " + me->query("id"));
                return 1;
                          }
      if(arg == "佛性常清净，何处有尘埃") {
          message_vision(CYN"$N诵道：佛性常清净，何处有尘埃。\n"NOR,this_player());
          command("thumb " + me->query("id"));
          if( me->query_temp("baochai") ) {
           command("hmm " + me->query("id"));
           command("可惜你已经答过了。\n");
           return 1;
           }
          if(present("jin shuaijian", me)){
            command("say 本想送你一支金甩箭做记念，可你已经有了。\n");
            command("say 我给你一盒黑玉断续膏吧。\n");
            new("/u/fly/heiyu")->move(me);
            message_vision("薛宝钗交给$N一盒黑玉断续膏。\n",this_player());
            me->set_temp("baochai", 1);             
            return 1;
            } 
         else {     
          command("say 这支金箭就给你作记念吧。\n");
          new("/u/fly/jin-sjian")->move(me);
          message_vision("薛宝钗交给$N一支金甩箭。\n",this_player());          
          me->set_temp("baochai", 1);
          return 1;
             }
           }
      else {
           message_vision(CYN"$N诵道：" + arg +"\n"NOR,this_player());
           command("angry");
           command("say 不懂装懂，你就别现了。\n");
           command("disapp " + me->query("id"));
           return 1;
           }
}
