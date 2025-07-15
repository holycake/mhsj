//By gslxz@mhsj 2001/6/19

#include <ansi.h>
#include <skill.h>

inherit F_CLEAN_UP;

int main(object me)
{
   if( me->is_ghost() )
     return notify_fail(HIB"做了鬼了，就老实点吧！\n"NOR);

   if (me->is_busy() || me->query_temp("doing_xiudao"))
		return notify_fail("你现在正忙着呢。\n");

   if( me->query("mana") < 200 )
		return notify_fail(HIR"你的法力不够了，不能够使用hujiu命令！\n"NOR);

   if(me->is_fighting())
   {return notify_fail(HIC"战斗中不能下"+HIR"hujiu"+HIC"指令 \n"NOR);  }

   if( time()-(int)this_player()->query_temp("hujiu_end") < 5&& !wizardp(this_player()) )
              return notify_fail(WHT"现在频繁的使用救命毫毛，以后怎么办！\n"NOR);

   else{
	write(HIW"你使用了救命毫毛，一阵烟雾将你裹住。\n\n"NOR);

      if( environment(me)->query("no_hujiu") )
		{return notify_fail(WHT"可惜你现在不能使用huifu命令！\n"NOR);  }
   else {

      this_player()->move(this_player()->query("startroom"));
  	             write(WHT"\n烟雾过后，你又回到了起点。\n"NOR);
          this_player()->set("mana",0);
    this_player()->set_temp("hujiu_end",time());
	
            return 1;
}
       }
}

int help(object me)
{
write(@HELP

这个指令只对新手有用。
HELP
	);
	return 1;
}
