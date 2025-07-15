// by gslxz@mhsj
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("教皇", ({"jiao huang", "huang"}));
        set("long", "传说中的教皇，他是邪恶的化身。\n");
        set("gender","男性");
        set("title", RED"【邪恶的化身】"NOR);
        set("age",37);
        set("con",60);
        set("per",32);
        set("str",80);
        set("int",80);
          set("combat_exp",10000000);
          set("daoxing",900000);
        set("chat_chance",20);
        set("chat_msg", ({
                "教皇说道：我要统治世界！\n"   
        }));
        set_skill("dodge", 600);
        set("cant_be_smashed",1);
        set("attitude", "friendly");
        set_skill("force", 600);
        set_skill("parry", 600);
        set_skill("unarmed", 600);
        set_skill("sword", 600);
        set_skill("westsword",600);
        set_skill("boxing",600);
        set_skill("balei",600);
        set_skill("spells",600);
        set_skill("shuangyu", 600);
        map_skill("sword","westsword");
        map_skill("unarmed","boxing");
        map_skill("spells","shuangyu");
        map_skill("dodge","balei");
        set("max_force", 30000);
        set("force", 60000);
        set("max_mana",30000);
        set("mana",60000);
        set("mana_factor",180);
        set("force_factor", 150);
        set("max_kee", 7000);
        set("max_gin", 7000);
        set("max_sen", 7000);
        setup();
        carry_object(__DIR__"obj/sy_cloth")->wear();
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
        object me=query_temp("my_killer");
        if( ! me ) return ;

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
        message_vision(HIG"$N手中令旗一挥，一阵狂风呼啸而起！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIG"$N被风吹的跪在地上，毫无半点力量！\n"NOR,me);
              me->add("eff_kee",-query("max_kee")/10);
              me->add("eff_sen",-query("max_sen")/10);
                }
        else
        message_vision(HIG"$N在风中旋转着，借助风的力量继续作战！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(HIC"$N一挥手中令旗，一道闪电劈向$n！\n",ob,me);

        if(random(3)==0)

                {
              message_vision(HIC"$N被闪电劈了个正着，直电的头皮发麻！\n"NOR,me);
              me->add("eff_kee",-35*query("max_kee")/10);
              me->add("eff_sen",-35*query("max_sen")/10);
                }
        else
        message_vision(HIC"$N早就看清了闪电的方向，轻轻一闪，躲开了。\n"NOR,me);
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

        if((ob&&ob->query("12gong/shuangyu")=="done") && (ob&&ob->query("12gong/jiaohuang")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "杀死教皇，终于闯完了黄金十二宫！\n"NOR,users());
        ob->set("12gong/jiaohuang","done");
        ob->add("12gong/number",1);
              ob->save();
          ob->add("daoxing", 500000);
         tell_object(ob,"你赢得了一百二十年道行");
        }
       ::die();
}
