#include <ansi.h>

inherit ITEM;


void create()
{
        set_name("礼品柜", ({ "cabinet",  }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个很大的礼品柜，每到一个周末你都可以到这里来拿（na all from cabinet）一件你的礼物。\n");
                set("value", 1000);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();

}


void init()
{
     add_action("do_qu","na");
}


int do_qu(string arg)
{ 
    object me,ob;
    mapping skl;
    string *sname;
    int i,how=0;
    string week, month, day, time, year;
    string item,from,check;
    
     if ( !arg )
          return notify_fail("命令格式： na all from cabinet \n");     

     sscanf(arg, "%s from %s", item,  from);

     if(from!="cabinet")
          return notify_fail("命令格式： na all from cabinet \n");     

            
     if(item!="all"&&item!="礼品盒")
          return notify_fail("你想拿什么？\n");     


     sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
    if(day=="")
     sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time, year);

    me = this_player();

    if ((int)me->query("combat_exp") <3000 || (int)me->query("mud_age")<36000)
        return notify_fail("嘿嘿，想登新玩家来骗我，没门！。\n");
      
    if ((int)me->query("combat_exp") >=3000 ) 
         {
		
	    skl = me->query_skills();
if( skl==0 )return notify_fail("你好意思去拿？再练一会吧！\n");
            sname  = keys(skl);
            for(i=0; i<sizeof(skl); i++)
                   if (skl[sname[i]] >= 20)how=how+1; 
                          if(how<3)
                            return notify_fail("你好意思去拿？再练一会吧！\n");
	
          } 
     
     check=year+month+day;            
     if(me->query("weekend_gift")==check)
       return notify_fail("你好象拿过了耶！\n");

     ob = new("/clone/guo");
     ob->move(me);
     me->set("weekend_gift",check);
     return notify_fail("你从礼品柜里拿出一个"+HIR"礼品盒"NOR+"。\n");
}


//int is_container() { return 1; }
  
