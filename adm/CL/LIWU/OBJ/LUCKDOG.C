#include <ansi.h>

inherit NPC;

  string *fail_action=({
                    "kill",
                    "steal",
                    "touxi",
                    "ansuan",
                    "chat*",
                       });


void create()
{
        set_name("哈巴狗", ({ "haba gou" ,"gou","dog"}) );
        set("title", HIY"吉祥狗"NOR);
        set("race", "野兽");    
        set("long", "这是一只很可爱的宠物狗，它正摇着尾巴对你「汪、汪」直叫。\n");
        set("attitude", "friendly");
        set("age", 2);
        set("str", 40);
        set("cor", 40);
        set("int", 40);

	set("limbs", ({ "头部", "前爪", "后脚", "尾巴", "身体"}) );
	set("verbs", ({  "claw","bite" }) );

	set_temp("apply/attack", 10);
	set_temp("apply/defense", 20);
        set("combat_exp",1500);
        set_skill("unarmed",20);
        set_skill("dodge",30);
        set_skill("parry",30);
        set("qi", 500);
        set("max_qi", 500);
        set("jing", 200);
        set("max_jing", 200);  
        setup();
        
}

void init()
{
    add_action("accept_order", "order");
}


int accept_order(string verb)
{
        object me,dog;
        string name, dothing,action,temp;
        int i;
        me = this_player();

        if( !verb || sscanf(verb, "%s to %s", name, dothing)<2 )
                return notify_fail("你要命令谁干什麽事？\n");
                
             dog=present(name,environment(me));
              if(dog!=this_object())
                {
                   return 0;
                } 
              if(!dog)
             return notify_fail("有这件物品吗？\n");

           if(dog->query("boss_id")!=me->query("id"))
             return notify_fail("这只哈巴狗不是你的吧？\n");
               
         for(i=0;i<sizeof(fail_action);i++)
          {
             sscanf(dothing,"%s %s",action,temp);
            if(action==fail_action[i])

              return notify_fail("你的哈巴狗对你摇了摇头，似乎不愿意接受你的命令。\n");
          }
      tell_room(environment(me),me->name(1)+"轻轻跟"+dog->query("name")+"说了几句话，"
       +dog->query("name")+"会意地摇了摇尾巴。\n",me);

      tell_object(me,"你对"+dog->query("name")+"说：「"+dothing+"」，"
       +dog->query("name")+"会意地摇了摇尾巴。\n");
          command( dothing );           
        return 1;
}

int accept_info(object me, string command)
{
        return (string)me->query("id") == (string)query("boss_id");
}


int accept_object(object me, object obj)
{   
    if(this_object()->query("boss_id")!=me->query("id"))
     {
      tell_object(me,"你想毒害人家的吉祥物呀？\n");
      return 0;
     }
    if(obj->query("food_supply"))
      message_vision(this_object()->query("name")+"高兴地对$N「汪、汪」直叫 。\n",me);
    else
      message_vision(this_object()->query("name")+"对$N摇了摇尾巴 。\n",me);
      return 1;
}
