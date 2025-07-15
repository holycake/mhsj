// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
#include <ansi.h>
void create()
{
       set_name("女守卫", ({"guard"}));
       set("long",
"一个妲几的高级弟子,被派来看守门户.不容别派弟子闯入.\n");
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

      
create_family("轩辕墓", 3, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
       carry_object("/clone/weapon/needle1")->wield();
}
void init()
{
        add_action("do_answer", "answer");
}

int do_answer(string arg)
{
        if( !arg ) return notify_fail("你说什么？\n");
        this_player()->set_temp("pending/jiangjun_answer", 0);
        message_vision("$N答道：" + arg + "\n", this_player());
        if( arg== "参拜" ) {
                command("haha");
                command("say 原来是参拜我们娘娘的呀,欢迎欢迎！\n");
                this_player()->set_temp("pending/jiangjun_answer", 1);
        } else {
                command("say 你到底要干什么？说清楚再过去！\n");
        }
        return 1;
}
