// by gslxz@MHSJ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("阿波罗", ({"apolo", "shi zi"}));
        set("long", "传说中的太阳神－阿波罗，守护着狮子座。\n");
        set("gender","男性");
        set("title", HIY"【狮子神】"NOR);
        set("age",37);
        set("con",40);
        set("spi",50);
        set("per",30);
        set("str",35);
        set("int",45);
            set("combat_exp",9000000);
        set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "太阳神－阿波罗说道：不知何时能再见到雅典娜！\n"   
        }));
        set("attitude", "friendly");
        set_skill("dodge", 550);
        set_skill("force", 550);
        set_skill("parry", 550);
        set_skill("unarmed", 550);
        set_skill("sword", 550);
        set_skill("westsword",550);
        set_skill("boxing",550);
        set_skill("balei",550);
        set_skill("spells",550);
        set_skill("jinniu", 550);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","jinniu");
        map_skill("dodge","balei");
        set("max_force", 14000);
        set("force", 280000);
        set("max_mana",14000);
        set("mana",4000);
        set("mana_factor",100);
        set("force_factor", 100);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/shz_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;

 if( me->is_ghost() )
     {
     remove_call_out("check");
     return;
     }
if(!present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }
     switch(random(6))
     {        
        case 0:
        {
        message_vision(HIC"$N张开大嘴，居然吐出一团青光，罩向$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"青光如雨点般落在$N的身上！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIC"$N大吼一声，居然把青光反弹了回去。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N手指太阳，只见阳光突然变强，照得人睁不开眼！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIC"$N感觉到浑身如针扎般刺痛。\n"NOR,me);
              me->add("eff_kee",-5*query("max_kee")/10);
              me->add("eff_sen",-5*query("max_sen")/10);
                }
        else
        message_vision(HIC"阳光照在$N的身上，$N感到无限的暇意。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIC"$N在怀里摸索着什么......居然是一只狮子，狮子向$n扑去。\n",ob,me);
                              
                if(random(2)==0)

                {
              message_vision(HIY"$N不知如何是好，狮子趁机猛咬了一口！\n"NOR,me);
              me->start_busy(1);
              me->add("eff_kee",-10*query("max_kee")/10);
              me->add("eff_sen",-10*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N仔细一看，原来是个纸做的狮子！\n"NOR,me,ob);
        }
        break;

  }
        if( random(8) == 5 )
        powerup();

        remove_call_out("check");
        call_out("check",2+random(3));
}
void die()
{

        object ob = query_temp("my_killer");

        if((ob&&ob->query("12gong/juxie")=="done") && (ob&&ob->query("12gong/shizi")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第五宫狮子座，继续向黄金战士前进。\n"NOR,users());
        ob->set("12gong/shizi","done");
        ob->add("12gong/number",1);
       ob->add("daoxing", 50000);
       tell_object(ob,"你赢得了五十年道行");
       ob->set("title",HIW"狮子座战士"NOR);
         ob->save();

        }
       ::die();
}
