// by gslxz@MHSJ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("宙斯", ({"zhou si", "ren ma"}));
        set("long", "传说中的天帝宙斯，守护着人马座.\n");
        set("gender","男性");
        set("title", HIY"【天帝】"NOR);
        set("age",37);
        set("con",40);
        set("per",30);
        set("str",43);
        set("int",54);
          set("combat_exp",8600000);
          set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "宙斯说道：不知何时能再见到雅典娜！\n"   
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
        set_skill("renma", 550);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","renma");
        map_skill("dodge","balei");
        set("max_force", 17000);
        set("force", 34000);
        set("max_mana",17000);
        set("mana",34000);
        set("mana_factor",160);
        set("force_factor", 160);
        set("max_kee", 5500);
        set("max_gin", 5500);
        set("max_sen", 5500);

        setup();
        carry_object(__DIR__"obj/rm_cloth")->wear();
        carry_object("/d/obj/weapon/sword/westsword")->wield();
}
void init()
{
        add_action("do_none","perform");
        add_action("do_none","cast");
        add_action("do_none","ji");
}
int do_none()
{
        object me = this_object();
        message_vision("$N冷笑一声：我乃$N，你想耍什么花样？\n",me);
        return 1;
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
        message_vision(HIY"$N手指$n，$N的指尖突然串出一道白光！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIY"白光之后，$N感到身上无比的疼痛！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIW"$N毫无惧色，一个转身，躲开了白光。\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一吹口哨，一只半人半马的怪物向$n冲 去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIM"$N被怪物一口咬中了要害！\n"NOR,me);
              me->add("eff_kee",-7*query("max_kee")/10);
              me->add("eff_sen",-7*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N振作精神，仔细一看，原来只是幻象。\n"NOR,me);
        }
        break;

        case 2:
        {

        message_vision(HIW"$N双手合十，禁闭双眼，$n顿时迷惑起来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIM"$N感觉浑身的力量正从脚下被吸走！\n"NOR,me);
              me->add("eff_kee",-18*query("max_kee")/10);
              me->add("eff_sen",-18*query("max_sen")/10);
                }
        else
        message_vision(HIG"$N站稳脚跟，好象在和大地搏斗。\n"NOR,me);
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

        if((ob&&ob->query("12gong/tianxie")=="done") && (ob&&ob->query("12gong/renma")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第九宫：人马宫，向黄金战士努力！\n"NOR,users());
        ob->set("12gong/renma","done");
        ob->add("12gong/number",1);
         ob->add("daoxing", 290000);
          tell_object(ob,"你赢得了九十年道行");
   ob->set("title",HIW"人马座战士"NOR);
            ob->save();

        }
       ::die();
}
