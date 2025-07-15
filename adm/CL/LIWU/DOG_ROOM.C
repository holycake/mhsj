// Room: /d/liwu/dog_room.c

inherit ROOM;
#include <ansi.h>
#include <dbase.h>



void create()
{
	set("short", HIC"宠物寄养屋"NOR);
	set("long", @LONG
这是一个规模不很大的宠物寄养屋，远远你就可以听到后院的狗吠声，
大概是它们住的不习惯吧。在每一次退出前你可以把你的宠物先寄养到这里
。柜台后面有一个笑眯眯的小姑娘正在忙着接来客。柜台的旁边放了一快大
大的牌子(sigh)。
LONG
	);

	set("exits", ([
		
                "northeast"      :__DIR__"dogjie",
	]));

        set("item_desc", ([
		"sigh" : "本店提供寄养宠物服务：
         寄养：   jiyang  <宠物名>
         领回：   linghui <宠物序号> 
         改名：   name <宠物> <名字>
         查看：   chakan     
寄养或改名都收一两黄金的费用。每人限寄养两只宠物。      \n",
                            
	]));

	set("objects", ([
		__DIR__"npc/siyang_yuan" : 1,

	]));

	setup();
	
}

 void init()
 {
    add_action("do_jiyang","jiyang");
    add_action("do_linghui","linghui");
    add_action("do_chakan","chakan");
    add_action("do_name","name");
  }

 int do_name(string arg)
 {
   object me=this_player();
   object ob;
   string dog_id,dog_name;

      
   if(!objectp(present("siyang yuan", environment(me))))
          return 0;  
   if(!arg)
      return notify_fail("你要改什么？\n");
   
   sscanf(arg, "%s %s", dog_id,  dog_name);

   if(!dog_id||!dog_name)
      return notify_fail("你要改什么？\n");
   
   ob =present(dog_id,environment(me));

   if(!ob)
      return notify_fail("这里好象没有这只宠物吧！\n");
 
   if(ob->query("boss_id")==me->query("id"))
       {
   switch (MONEY_D->player_pay(this_player(), 10000))
      {
	case 0:  //destruct(ob);    
		return notify_fail("改宠物的名字需一两黄金的费用耶！\n");
	case 2:  //destruct(ob);    
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
        ob->set("name","("+me->name(1)+"的)"+dog_name);
        message_vision("$N给了一两黄金给饲养员。\n",me);
        return 1;
      }
       }
    else return notify_fail("去把你的宠物带来！\n");
}
       
   

    
    

 int do_chakan()
 {
      object me=this_player();
          int i;
       
     if(!objectp(present("siyang yuan", environment(me))))
                 return 0;

     if(me->query("total_jiyang_count")==0)
        tell_object(me,"你目前没寄养任何宠物。\n");
       else 
        {
    	printf("你寄养的宠物有：\n");
		for (i = 1; i <=me->query("total_jiyang_count") ; i++)
                   printf("%3d   %s\n",i,me->query("chongwu_name"+i));
          }
	return 1;
  }

  int do_jiyang(string arg)
  {
   
       object me=this_player(),ob;
       string directory;
       int count,i;

       if(!objectp(present("siyang yuan", environment(me))))
                 return 0;
      if(query_temp("busy"))
        {tell_object(this_player(),"饲养员地对你说:\"稍等一会儿。\"\n");return 1;}  

       if(me->is_busy())
            return notify_fail("你正忙着呢！\n");  

       if(!arg)
             return notify_fail("你要寄养什么？\n");

           
       count=(int)me->query("total_jiyang_count"); 
       if(count>=2)
              return notify_fail("你已寄养了两只宠物了。\n");
              
       ob =present(arg,environment(me));
       if(!ob)
          return notify_fail("这里好象没有这只宠物吧！\n");
       if(ob->query("boss_id")==me->query("id"))
         {

/*******Save data************/

           count++;
           directory=base_name(ob);
           me->set("chongwu_dir"+count,directory);
           me->set("chongwu_name"+count,(string)ob->query("name"));
           me->set("chongwu_combat_exp"+count,(int)ob->query("combat_exp"));
           me->set("chongwu_mud_age"+count,(int)ob->query("mud_age"));
           me->set("total_jiyang_count",count);
           me->start_busy(1);

/***************************/

           message_vision("$N把一"+ob->query("unit")+ob->query("name")+"交给了饲养员。\n",me);                                  
           destruct(ob);    
           set_temp("busy",1);
           call_out("del_busy",1);  

           return 1;

           
         }
        
        return notify_fail("去把你的宠物带来！\n");
   }


int do_linghui(string arg)
 {
      object me=this_player(),ob;
          int order,i;

    if(!objectp(present("siyang yuan", environment(me))))
                 return 0;
    if(query_temp("busy"))
        {tell_object(this_player(),"饲养员地对你说:\"稍等一会儿。\"\n");return 1;}  

     if(!arg  || arg=="")
         return notify_fail("你想领回什么宠物？\n");

    sscanf(arg,"%d",order);
      order-=1;  
      
    if(me->is_busy())
        return notify_fail("你正忙着呢！\n");  

     else if(order<0||order>=me->query("total_jiyang_count"))
          printf("你好象没有寄养这宠物吧？\n");
     else 
      {    order+=1;
                
        ob=new(me->query("chongwu_dir"+order));
	switch (MONEY_D->player_pay(this_player(), 10000)) {
	case 0:  //destruct(ob);    
		return notify_fail("领回宠物需一两黄金的费用耶！\n");
	case 2:  //destruct(ob);    
		return notify_fail("您的零钱不够了，银票又没人找得开。\n");
	default:
 /***********Load data***************/
            ob=new(me->query("chongwu_dir"+order));
            ob->set("combat_exp",me->query("chongwu_combat_exp"+order));
            ob->set("boss_id",me->query("id"));
            ob->set("mud_age",me->query("chongwu_mud_age"+order));
            ob->set("gender","雄性");
            ob->set("name",me->query("chongwu_name"+order));
            ob->set_leader(me);
 /***********************************/


            me->set("total_jiyang_count",me->query("total_jiyang_count")-1);
            me->start_busy(1);
                for(i=order;i<=me->query("total_jiyang_count");i++)
                   {
                      me->set("chong_dir"+i,(string)me->query("chongwu_dir"+i+1));
		      me->set("chong_name"+i,(string)me->query("chongwu_name"+i+1));	
                    }
            if(me->query("chongwu_mud_age"+order)> 286400)
               { 
                  destruct(ob);
                  return notify_fail("饲养员说：你的宠物因为年龄过大死了。\n");
               }
            ob->move(environment(me));
          
      message_vision("$N从饲养员那里领回一"+ob->query("unit")+ob->query("name")+"。\n",me);
      set_temp("busy",1);
           call_out("del_busy",1);  
	}
      }

	return 1;
  }


  
void del_busy()
{
   delete_temp("busy");
}
