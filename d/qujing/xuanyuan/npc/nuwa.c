// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
//made by justin 
//change.c
inherit NPC;

void create()
{
       set_name("女娲", ({"nu wa", "master"}));
       set("gender", "女性");
       set("age", 60);
       set("class", "xian");
       set("attitude", "friendly");
       set("per", 30);
   set("int", 30);
       set("max_kee", 900);
       set("max_gin", 600);
       set("max_sen", 800);
       set("force", 800);
       set("max_force", 800);
       set("force_factor", 50);
       set("max_mana", 600);
       set("mana", 600);
       set("mana_factor", 40);
       set("combat_exp", 1400000);

        set("eff_dx", 200000);
        set("nkgain", 350);

       set_skill("literate", 180);
       set_skill("unarmed", 130);
       set_skill("dodge", 180);
       set_skill("force", 180);
       set_skill("parry", 180);
       set_skill("blade", 180);
       set_skill("spells", 180);
        set_skill("xuanhu-shentong", 160);
        set_skill("fox-hand", 160);
        set_skill("xuanhu-xinfa", 180);
        set_skill("xuanhu-blade", 180);
        set_skill("tianyi-zhen", 160);
        set_skill("huxing-step", 200);
        map_skill("spells", "xuanhu-shentong");
        map_skill("force", "xuanhu-xinfa");
        map_skill("blade", "xuanhu-blade");
        map_skill("unarmed","tianyi-zhen");
        map_skill("parry", "xuanhu-blade");
        map_skill("dodge", "huxing-step");

create_family("轩辕古墓", 2, "弟子");
setup();

        carry_object("/d/moon/obj/luoyi")->wear();
        carry_object("/d/obj/weapon/throwing/needle")->wield();
}
void init()
{
  int i;
  object who=this_player();
  if( ! who->query("obstacle/tianzhu") )
    return;
  if (who->query("combat_exp") < 10000)
  return;
  if (who->query("obstacle/xuanyuan") == "done")
  return;
  if(!who->query_temp("obstacle/daji_killed"))
  return;
  if(! who->query_temp("can_in") )
  return;
  if(! present("zhou wang",environment(who) ) )
  return ;
  i = random(600);
  who->add("obstacle/number",1);
  who->set("obstacle/xuanyuan","done");
  who->add("combat_exp",i+8000);
  who->delete_temp("gumupass");
  command("chat "+who->query("name")+"轩辕墓救纣王脱牢笼！");
  command("chat "+who->query("name")+"顺利闯过西行[1;37m第三十五关[m！");
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
  this_object()->move("/obj/empty");
}






