// by gslxz@MHSJ
inherit NPC;
#include "star.h"
#include <ansi.h>;
void get_date();
 
void create()
{
        set_name("阿雷斯", ({"aleisi", "bai yang"}));
        set("long", "传说中的站神阿雷斯，守护着白羊座\n");
        set("gender","男性");
            set("title", HIY"【战神】"NOR);
        set("age",37);
        set("attitude", "friendly");
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
            set("combat_exp",7700000);
          set("daoxing",7600000);
        set("chat_chance",20);
        set("chat_msg", ({
                "阿雷斯说道：不知何时能再见到雅典娜！\n"   
        }));
          set_skill("dodge", 500);
          set_skill("force", 500);
          set_skill("parry", 500);
          set_skill("unarmed", 500);
          set_skill("sword", 500);
         set_skill("westsword",500);
          set_skill("boxing",500);
         set_skill("baiyang", 500);
        set_skill("baiyang", 500);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","baiyang");
         set("max_force", 8000);
         set("force", 16000);
         set("max_mana",8000);
         set("mana",16000);
         set("mana_factor",200);
         set("force_factor", 200);
       set("max_kee", 3000);
       set("max_gin", 3000);
        set("max_sen", 3000);

        setup();
        carry_object(__DIR__"obj/by_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
    
     if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
      
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIR"$N双手一挥，一团烈火直冲$n而去！\n",ob,me);

        if(random(2))
        
                {
              message_vision(HIR"$N被$n的烈火烧个焦头焦脸！\n"NOR,me,ob);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIR"$N轻而易举的躲过了$n的攻击！\n"NOR,me,ob);
        }
        break;


        case 1:
        {

        message_vision(HIR"$N吹了起横笛，顿时一只白羊向$n直冲而去！\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N被白羊撞了个人仰马翻！\n"NOR,me);
              me->add("eff_kee",-10*query("max_kee")/10);
              me->add("eff_sen",-10*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N对着白羊大喝一声：停！白羊乖乖从旁边溜开了！\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N手中长剑变的硕大无比，直插$n后腰\n",ob,me);

        if(random(2))

                {
              message_vision(HIR"$N顿时血流如注，顷刻染红了全身！\n"NOR,me);
              me->add("eff_kee",-20*query("max_kee")/10);
              me->add("eff_sen",-20*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N顺着剑的方向，纵身跃起，躲过这致命一击！\n"NOR,me);
        }
        break;

  }
 //       if( present(me,environment()) )  return ;

        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if(ob&&ob->query("12gong/baiyang")!="done")
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了"+environment(ob)->query("short")+"\n"NOR,users());
        ob->set("12gong/baiyang","done");
        ob->add("12gong/number",1);
         ob->add("daoxing", 10000);
    ob->set("title",HIW"白羊座战士"NOR);
       ob->save();
        tell_object(ob,"你赢得了十年道行");
        
        }
       ::die();
}
