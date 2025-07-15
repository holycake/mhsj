// by gslxz@MHSJ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("哈迪斯", ({"hadis", "tian xie"}));
        set("long", "传说中的冥王哈迪斯 ，守护着天蝎座.\n");
        set("gender","男性");
        set("title", HIY"【冥王】"NOR);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
            set("combat_exp",8900000);
          set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "哈迪斯说道：不知何时能再见到雅典娜！\n"   
        }));
        set_skill("dodge", 550);
        set("attitude", "friendly");
        set_skill("force", 550);
        set_skill("parry", 550);
        set_skill("unarmed", 550);
        set_skill("sword", 550);
        set_skill("westsword",550);
        set_skill("boxing",550);
        set_skill("balei",550);
        set_skill("spells",550);
        set_skill("tianxie", 550);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","tianxie");
        map_skill("dodge","balei");
        set("max_force", 16000);
        set("force", 32000);
        set("max_mana",16000);
        set("mana",32000);
        set("mana_factor",150);
        set("force_factor", 150);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/tx_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
 
void check()
{
        object ob=this_object();
        object ghost;
        object me=query_temp("my_killer");
        if( ! me ) return ;
if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                      
     switch(random(6))
     {        
        case 0:
        {
        message_vision(YEL"$N一声狂笑，巨波排山倒海般向$n冲去。！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(YEL"$N在波涛中摇摆着！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
else        message_vision(YEL"$N如鱼得水，反而加强了进攻。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N吹了一口气，一股绿色的毒气向$n喷去！\n",ob,me);

        if(random(2)==0)

                {
              message_vision(YEL"$N顿时被熏晕了头！\n"NOR,me);
              me->add("eff_kee",-25*query("max_kee")/10);
              me->add("eff_sen",-25*query("max_sen")/10);
                }
        else
        message_vision(YEL"$N旋转不停，不多一会毒气消失的无影无踪。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIR"$N口念咒语：小鬼何在？\n",ob);
        ghost=new("/obj/npc/ghost.c");
        ghost->move(environment());
        ghost->set("combat_exp",ob->query("combat_exp"));
        ghost->set("max_kee",ob->query("max_kee"));
        ghost->set("max_sen",ob->query("max_sen"));
        ghost->kill_ob(ob);
        message_vision(HIC"不知从何处串出来几个小鬼向$N杀去！\n"NOR,me);
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

        if((ob&&ob->query("12gong/tiancheng")=="done") && (ob&&ob->query("12gong/tianxie")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第八宫：天蝎宫，继续向黄金战士努力！\n"NOR,users());
        ob->set("12gong/tianxie","done");
        ob->add("12gong/number",1);
    ob->set("title",HIW"天蝎座战士"NOR);
           ob->save();
         ob->add("daoxing", 280000);
       tell_object(ob,"你赢得了八十年道行");

        }
       ::die();
}
