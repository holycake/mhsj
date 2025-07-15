#include <ansi.h>
inherit NPC;
string ask_tea();
int singing();
#include "/u/fly/npc/npc.h";
void create()
{
       set_name("黛玉", ({ "daiyu"}) );
       set("title", MAG "病如西子胜三分" NOR);
       set("gender", "女性" );
       set("shen_type", 1);
       set("age", 16);
       set("str", 10);
       set("con", 40);
       set("int", 40);
       set("dex", 40);
       set("per", 100);
       set("kar", 50);
       set("no_clean_up",1);
       set("long",
HIW"金陵十二钗之一的林黛玉，
态生两靥之愁，娇袭一身之病。
闲静时如姣花照水，行动处似弱柳扶风。\n"NOR );
       set("combat_exp", 20000);
       set("attitude", "peaceful");
       set("max_qi", 300);
       set("max_jing", 300);
       set("neili", 100);
       set("max_neili", 100);
       set_skill("literate", 500);
       set("inquiry", ([
                   "name" : "小女子林黛玉。",
                   "here" : "这里是镜花居乐室。",
                   "fly" : "fly就是飞雪啊，你怎么蠢得连这都不知道？",
                   "飞雪" : "就是这里的主人啊，你怎么蠢得连这都不知道？",
                   "薛宝钗" : "她是我姐姐。",
                   "宝钗" : "她是我姐姐。",
                   "茶" : (: ask_tea :), 
                   "tea" : (: ask_tea :),
       ]) );
       setup();
       set("chat_chance", 2);
       set("chat_msg", ({
 "黛玉打开扇子掩着嘴，轻轻咳嗽了两声。。\n",
 "黛玉轻声吟道：可叹停机德，堪怜咏絮才。\n",
 "黛玉眼往窗外发起呆来。\n",
 (: singing :),  
       }) );
       carry_object("/u/fly/obj/pipa");
       carry_object("/u/fly/obj/qupu");
       carry_object("/u/fly/obj/jinshan")->wield();
       if( clonep() ) CHANNEL_D->register_relay_channel("chat");
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
}
void greeting(object ob)
{
        if( !ob || environment(ob) != environment() ) return;
        if((string)ob->query("id")=="fly") return;
        if(ob->query_temp("kill_daiyu"))
               {
                message_vision("黛玉眉头一皱：这个无理之徒又来了，赶他出去！\n",ob);
                message_vision("只见几个家丁跑进来，把$N乱棒赶了出去。\n",ob);
                ob->move("/d/city/kezhan");
                ob->receive_damage("qi", 100);
                message_vision(ob->name() + "又被人乱棒打了出来。\n",ob);
        }
        else
                say("黛玉道了个万福：这位" + RANK_D->query_respect(ob)
              + "请进，欢迎来此做客。\n");
}
