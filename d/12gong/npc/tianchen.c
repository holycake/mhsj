// by gslxz@MHSJ
 
#include <ansi.h>;
inherit NPC;
#include "star.h"
 
void create()
{
        set_name("童虎", ({"tong hu", "tian chen"}));
        set("long", "传说中在庐山五老峰静坐0243年的中国老人\n");
        set("gender","男性");
        set("title", HIY"【龙圣】"NOR);
        set("age",37);
        set("con",30);
        set("per",30);
        set("str",25);
        set("int",35);
            set("combat_exp",8700000);
        set("daoxing",8000000);
        set("chat_chance",20);
        set("chat_msg", ({
                "童虎说道：只有中国才有最好的功夫。\n",
        }));
        set_skill("dodge", 550);
        set("attitude", "friendly");
        set_skill("force", 550);
        set_skill("parry", 550);
        set_skill("unarmed", 550);
        set_skill("staff", 550);
        set_skill("lunhui-zhang",550);
        set_skill("jienan-zhi",550);
        set_skill("lotusmove",550);
        set_skill("spells",550);
        set_skill("buddhism", 550);
        map_skill("staff","lunhui-zhnag");
        map_skill("unarmed","jienan-zhi");
        map_skill("spells","buddhism");
        map_skill("dodge","lotusmove");
        set("max_force", 15000);
        set("force", 30000);
        set("max_mana",15000);
        set("mana",30000);
        set("mana_factor",60);
        set("force_factor", 60);
        set("max_kee", 5000);
        set("max_gin", 5000);
        set("max_sen", 5000);

        setup();
        carry_object(__DIR__"obj/tc_cloth")->wear();
      carry_object("/d/obj/weapon/staff/chanzhang")->wield();
}
 
void check()
{
        object ob=this_object();
        object me=query_temp("my_killer");
        if( ! me ) return ;
   if(! present(me,environment()) )
     {
     remove_call_out("check");
     return;
     }                               

     switch(random(5))
     {        
        case 0:
        {
        message_vision(HIC"$N大喊一声『庐山升龙霸』一条居龙自九天而起，直飞$n！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(HIC"$N被巨龙在空中顶得翻了几十个跟头！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else        message_vision(HIG"$N身型急转，不知道绕了多少圈才夺过巨龙的攻击！\n"NOR,me);
        }
        break;


        case 1:
        {

        message_vision(YEL"$N高喊一声：『庐山亢龙霸』，一条恶龙自溅底而出，尾巴向$n扫去！\n",ob,me);

        if(random(2)==0)
                {
              message_vision(GRN"$N被恶龙的尾巴甩了个正着，$N顿时眼冒金星！\n"NOR,me);
              me->add("eff_kee",-2*query("max_kee")/10);
              me->add("eff_sen",-2*query("max_sen")/10);
                }
        else
        message_vision(HIY"$N用尽全身力气，飞升而气，恶龙的尾巴正从$N的脚底板扫过！\n"NOR,me);

        } 
        break;

        case 2:
        {

        message_vision(HIR"$N高喊一声：『庐山百龙霸』，无数只巨龙向$n冲过来！\n",ob,me);

                if(random(2)==0)

                {
              message_vision(HIR"$N如一个球一样，被无数只巨龙在空中戏弄着！\n"NOR,me);
              me->add("eff_kee",-3*query("max_kee")/10);
              me->add("eff_sen",-3*query("max_sen")/10);
                }
        else
        message_vision(HIR"$N看准了巨龙之间的空隙，左转右转，才勉强离难！\n"NOR,me,ob);
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

        if((ob&&ob->query("12gong/shinu")=="done") && (ob&&ob->query("12gong/tiancheng")!="done"))
        {
        ob->start_busy(3);
        message("chat",HIY+"【黄金十二宫】雅典娜(Ya dian na):"+ob->name()+
        "闯过了第七宫：天秤宫!\n"NOR,users());
        ob->set("12gong/tiancheng","done");
        ob->add("12gong/number",1);
          ob->add("daoxing", 270000);
    ob->set("title",HIW"天平座战士"NOR);
          ob->save();
         tell_object(ob,"你赢得了七十年道行");

        }
       ::die();
}
