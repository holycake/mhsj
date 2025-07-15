#include <ansi.h>
#include <dbase.h>

inherit NPC;

void create()
{
  set_name("小马崽", ({ "ma zai", "zai" }) );
  set("race", "野兽");
  set("age", 2);
  set("long", "一只刚生下来的小马崽，正使尽全身的力气想站起来。\n");
  set("per", 10+random(20));
  set("eff_kee", 50);
  set("eff_sen", 50);
  set("combat_exp", 0);
  set("daoxing", 0);

  set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
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
            "小马崽发出轻轻的叫声。\n",
            "小马崽一个不小心，摔倒在地上。\n",
            "小马崽喘着粗气。\n",
            "小马崽抬起前腿，奋力想站起来。\n",
        }) );

        add_action("do_feed", "feed");
}

int do_feed(string arg)
{
        object me,feeob;
        object hb = this_object();

        me = this_player();
        
   
        if ( !arg || !(feeob=present(arg, me)) )
           return notify_fail("你要给小马崽喂什么吃？\n");

        else if (arg != "grass") 
           return notify_fail("这东西小马崽吃不了。\n");  

        else 
                { 
                if (me->query("kee")>10)  me->add("kee",-10); 
                else
                   {
                   me->unconcious();
                   return 1;
                   }

                destruct(feeob);



                if ( random(20) != 0 )
                message_vision("$N给小马崽喂了一些青草，小马崽津津有味的吃了起来。\n", me);

                else
                  {
                  object smallhorse;
                  message_vision("小马崽吃了小草，前蹄一扬，站了起来。\n" , me,);
                  smallhorse = new (__DIR__"smallhorse");
                  smallhorse->move(environment());
                  destruct(hb);
                  }
                }
        return 1;
}

