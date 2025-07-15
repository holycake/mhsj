#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("小马驹", ({ "ma ju", "ju" }) );
  set("race", "野兽");
  set("age", 5);
  set("long", "一只尚未长大的小马驹。\n");
  set("per", 10+random(20));
  set("kee", 100);
  set("max_kee", 100);
  set("sen", 100);
  set("max_sen", 100);
  set("combat_exp", 4000);
  set("daoxing", 4000);

  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
  set("ride/msg", "牵");
  set("ride/dodge", 20);
  set("verbs", ({ "bite"}));

  set("chat_chance", 10);


  setup();
}

void init()
{
        object ob;

        ::init();
        set("chat_chance", 5);

        set("chat_msg", ({
            "小马驹轻轻的哼哼了几声。\n",
            "小马驹摩擦着前蹄。\n",
            "小马驹一副无精打采的样子。\n",
        }) );

        add_action("do_qian", "qian");
        add_action("do_mount", "mount");
}

int do_qian(string arg)
{
        object me = this_object();
        object who = this_player();


        if (arg != me->query("id"))
         return 0;


        else 
            { 
            if (who->query("kee")>50)  who->add("kee",-50); 
            else
               {
               who->unconcious();
               return 1;
               }

            if ( me->query("kee") == 100)
                {

                if ( random(20) != 0 )
                message_vision("$N牵着小马驹溜了一圈。\n", who);

                else
                     {
                     object smallhorse;
                     message_vision("$N一声嘶鸣，奋蹄疾奔。\n" , me,);
                     me->add("max_kee",200);
                     me->add("eff_kee",200);
                     me->add("kee",200);
                     }
                }
            else  message_vision("$N牵着小马驹溜了一圈，但小马驹依然无精打采。\n", who);

             }
        return 1;

}

int do_mount(object me)
{
        object who = this_player();
        me = this_object();

        if (me->query("kee")<200)  
           {
            message_vision("小马驹惨叫一声，率倒在地。\n\n", me);
            me->unconcious();
            return 1;
           }
}

