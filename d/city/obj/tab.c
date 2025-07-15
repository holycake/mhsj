#include <ansi.h>

inherit ITEM;


void create()
{
        set_name(HIC"魔幻世纪"+HIY"礼品台"NOR, ({ "table",  }) );
        set_weight(3000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", "这是一个很大的礼品台，每一个来到这里的新玩家都可以\n"+
                                                  "到这里来拿"HIR"（take gift from table）"NOR"一件你的礼物。\n");
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
     add_action("do_qu","take");
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
          return notify_fail("命令格式： take gift from table \n");     

     sscanf(arg, "%s from %s", item,  from);

     if(from!="table")
          return notify_fail("命令格式： take gift from table \n");     

            
     if(item!="gift"&&item!="礼品包")
          return notify_fail("你想拿什么？\n");     


     sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
    if(day=="")
     sscanf(ctime(time()), "%s %s  %s %s %s", week, month, day, time, year);

    me = this_player();

    if ((int)me->query("combat_exp") >=10000 || (int)me->query("mud_age")>=36000)
        return notify_fail(BLINK HIR"你好象已经拿过了吧，一人只有一份！\n"NOR);
      
    if ((int)me->query("combat_exp") <0 ) 
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
       return notify_fail(BLINK HIY"小朋友可不要太贪心哟!\n"NOR);

//         ob = new("/d/city/obj/gift1.c")
     return notify_fail("你从礼品台上拿出一个"+HIR"礼品包"NOR+"。\n");
}


//int is_container() { return 1; }
  
