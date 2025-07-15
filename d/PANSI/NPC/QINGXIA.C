
//zixiaxianzi.c 2001 by lestat
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_mieyao();
string ask_cancel();
string avenge();
string give_zui(object me);
void create()
{
       set_name(MAG"青霞仙子"NOR, ({"qingxia xianzi", "qingxia", "xianzi","master"}));
       set("long", "她是紫霞仙子的孪生姐姐,曾被佛祖把她和紫霞仙子捏在一棵灯芯里。後因紫霞仙子思凡
下界开山立派,故追至此处。\n");
       set("title", HIY"佛祖灯芯"NOR);
       set("gender", "女性");
       set("age", 20);
       set("class","xian");
       set("attitude", "friendly");
       set("rank_info/respect", "小姑娘");
       set("cor", 30);
       set("per", 21);
       set("max_kee", 4500);
       set("max_gin", 800);
       set("max_sen", 4500);
       set("force", 4000);
       set("max_force", 2400);
       set("force_factor", 125);
       set("max_mana", 1800);
       set("mana", 3000);
       set("mana_factor", 150);
       set("combat_exp", 1600000);
	   set("daoxing", 3000000);
       set_skill("literate", 150);
       set_skill("unarmed", 180);
       set_skill("dodge", 160);
       set_skill("force", 160);
       set_skill("parry", 150);
       set_skill("sword", 180);
       set_skill("spells", 150);
       set_skill("whip", 180);
   set_skill("pansi-dafa", 160);
   set_skill("lanhua-shou", 160);
   set_skill("jiuyin-xinjing", 150);
   set_skill("qingxia-jian", 200);
   set_skill("yueying-wubu", 150);
   set_skill("yinsuo-jinling", 150);
   map_skill("spells", "pansi-dafa");
   map_skill("unarmed", "lanhua-shou");
   map_skill("force", "jiuyin-xinjing");
   map_skill("sword", "qingxia-jian");
   map_skill("parry", "yinsuo-jinling");
   map_skill("dodge", "yueying-wubu");
   map_skill("whip", "yinsuo-jinling");
   set("chat_chance_combat", 50);
   set("inquiry", ([
          "复仇" : (: avenge :),
//		  "醉生梦死" : (: give_zui :),
           "修炼": (: ask_mieyao :),
           "cancel": (: ask_cancel :),
]));
   set("no_zui", 0);
create_family("盘丝洞", 1, "红");
setup();
        carry_object("/d/obj/cloth/tianyi.c")->wear();
        carry_object("/d/obj/weapon/sword/qinghong")->wield();
        carry_object("/d/ourhome/obj/shoes")->wear();
}
void init()
{
add_action("do_kneel","kneel");
add_action("do_yes", "yes");
}
string avenge()
{
    object who=this_player(),killer,where;
    string killid;
    if((string)who->query("family/family_name")!="盘丝洞")
        return ("你不是本派弟子，生死与我何干？");
    if(who->query("faith")<1000)
        return ("你在本门名望还不够，还需多加努力才行。");
    if(who->query("avenge/mud_age")>=who->query("death/mud_age"))
        return ("本座未闻死讯");
    killid=who->query("kill/last_killer");
    killer=find_living(killid);
    if(!killer||!userp(killer))
        return ("这个嘛，本座还得想一想");
    command("say 本座这就去为你抱仇。");
    who->set("avenge/mud_age",who->query("mud_age"));
    where=environment(who);
    tell_room(where,"只见青霞仙子向空中一指：\n");
    tell_room(where,"护法天尊何在，速去将"+killer->query("name")+"抓来。\n");
    tell_room(environment(killer),"空中伸出一只大手将"+killer->query("name")+"抓走了。\n");
    killer->move(where);
    tell_room(where,killer->query("name")+"被从空中扔了下来。\n");
    command("say 孽障，胆敢杀害我盘丝洞弟子");
    this_object()->kill_ob(killer);
    return("拿命来。");
} 
void attempt_apprentice(object ob)
{
   /*if ( !((string)ob->query("gender")=="女性")){
      command("shake");
          command("say 我们盘丝洞只收女徒，这位" + RANK_D->query_respect(ob) + "还是另请高就吧。\n");
      return;
   }*/
   if ( (string)ob->query("family/family_name")=="盘丝洞") {
   if (((int)ob->query("daoxing") < 500000 )) {
   command("say " + RANK_D->query_respect(ob) +
"的道行不够高深，有些绝学秘法恐怕难以领悟。\n");
   return;
   }
        command("pat "+ob->query("id"));
        command("say 好，希望" + RANK_D->query_respect(ob) +
"多加努力，把我们盘丝洞发扬光大。\n");
       command("recruit " + ob->query("id") );
	   ob->set("title", "盘丝洞青霞仙子传人");
	   ob->set("class", "xian");
   return;
   }
   command("shake");
   command("say " + RANK_D->query_respect(ob) +
"还是先去学些基础功夫吧。\n");
        return;
}
int accept_fight(object me)
{
   return 0;
}
string ask_mieyao()
{
    object who=this_player();
    if((string)who->query("family/family_name")=="盘丝洞") {
      command("smile "+who->query("id"));
      return "/d/obj/mieyao"->query_yao(who);
    }
    return ("非我门人,何故来此?\n");
}
int do_kneel()
{
    object who = this_player();
    if((string)who->query("family/family_name")!="盘丝洞")
     return notify_fail(this_object()->query("name")+"说：你又不是我座下弟子，拜我干什么？\n");
   if("/d/obj/mieyao"->delete_mieyao(who)){
        command("say 既然如此，就算了吧，不过你没有完成任务，得受些惩罚！\n");
	who->add("faith",-5);
        message_vision("$N的忠诚度下降了！\n",who);
     }
}
string ask_cancel()
{
    object me=this_player();
if((int)me->query_temp("m_mieyao"))
{
      me->add("daoxing",-2000);
      me->delete_temp("m_mieyao");
      me->delete("secmieyao");
      me->delete("secmieyao/type");
      me->delete("secmieyao/location");
      me->delete("secmieyao/place");
      me->delete("secmieyao/name");
      me->delete("secmieyao/id");
     return ("没用的东西！");
}
else
{
     return ("你有任务吗？！");
}
}
