// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

inherit NPC;
string ask_dan();
#include <ansi.h>
void create()
{
       set_name("炼丹小狐狸", ({"fox"}));
       set("long",
"一个专门负责炼丹的小狐狸.\n");
       set("gender", "女性");
       set("age", 20);
       set("class", "yaomo");
       set("attitude", "friendly");
       set("per", 30);
   set("int", 30);
       set("max_kee", 800);
       set("max_gin", 500);
       set("max_sen", 800);
       set("force", 500);
       set("max_force", 500);
       set("force_factor", 20);
       set("max_mana", 300);
       set("mana", 300);
       set("mana_factor", 20);
       set("combat_exp", 500000);

        set("eff_dx", 70000);
        set("nkgain", 260);

       set_skill("literate", 20);
       set_skill("unarmed", 50);
       set_skill("dodge", 80);
       set_skill("tianyi-zhen",80);
       set_skill("force", 50);
       set_skill("xuanhu-shentong", 60);
       set_skill("xuanhu-xinfa",80);
       set_skill("fox-hand",60);
       set_skill("huxing-step",80);
       set_skill("parry", 50);
       set_skill("spells", 50);
       map_skill("spells", "xuanhu-shentong");
     map_skill("force", "xuanhu-xinfa");
     map_skill("unarmed", "tianyi-zhen");
     map_skill("dodge", "huxing-step");
      set("inquiry", ([
          "炼丹": (: ask_dan :),
]));

create_family("轩辕古墓", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
       carry_object("/clone/weapon/needle1")->wield();
        carry_object("/d/qujing/xuanyuan/obj/tool");
}
void init()
{
	object me = this_object();
	remove_call_out("des");
	call_out("des",20,me);
}
void des(object me)
{
    destruct(me);
}
string ask_dan()
{
   object me=this_player();
   if((string)me->query("family/family_name")!="轩辕古墓")
      return ("您不是本门中人。");
 if(me->query("faith")>200||me->query("combat_exp")>100000)
      return ("您是本门大有名望之人，怎敢有劳您做这种杂务呢？");
      me->set("gm/dan",1);
   return ("好的，那你就用去炼丹吧。（zao dan）\n");
}
