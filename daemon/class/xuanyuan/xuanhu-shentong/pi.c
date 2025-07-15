
#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
   string msg,start;
   int ap, dp, success;
   target = offensive_target(me);
   //always use the one who is fighting me as target.

   if( me->is_busy())
     return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

   if( (int)me->query("mana") < 100 )

     return notify_fail("你的法力不够了！\n");

   if( (int)me->query("sen") < (int)me->query("max_sen")/5 )
     return notify_fail("你精神太差，难以集中精力念咒。\n");
   if(me->query("family/family_name") != "轩辕古墓")
   return notify_fail("你身非狐类,放不出这么臭的屁!\n");
   if( (int)me->query_skill("xuanhu-shentong", 1) < 20)
     return notify_fail("你未曾学会屁遁。\n");

   ap=me->query_skill("spells")+me->query("max_mana")/10;
   if(target) dp=target->query_skill("spells")+target->query("max_mana")/10;

   if(!me->is_fighting() )
   {
     message_vision(YEL"$N撅着屁股，对着天空猛放了几个臭屁。\n"NOR,me);
     me->add("sen", -me->query("max_sen")/8);
     me->add("mana", -80);
     success=1;
   }
   else
   {
     msg=YEL"$N突然跳出战圈，屁股一歪，一股臭气冲天而出。\n"NOR;

     if(random(ap+dp)>dp/2)
     {
        msg+=YEL"只听$N喝了一声「走！」，人影已经不见了.$n却被臭屁熏的摇摇欲坠！\n"NOR;
        me->add("sen", -me->query("max_sen")/6);
        me->add("mana", -50);
        if(target) target->add("sen",-80);
        success=1;
        me->remove_all_killer();
     }
     else msg+=YEL"但$n一皱眉头，一把抓住$N的尾巴。\n"NOR;
     me->add("mana", -50);
     message_vision(msg, me, target);
   }
   if(success)
   {
     start=me->query("env/destination");
     start=me->query("记号/"+start);
     if(!start || !find_object(start))
        start=me->query("startroom");
     if(!start) start="/d/xuanyuan/yongdao";
     me->move(start);
     message("vision", YEL+me->name()+"突然在一片臭气中爬了出来\n"NOR,
            environment(me), me);
     tell_object(me, YEL"你的身影突然出现在一片臭气中。\n"NOR);
     return 3+random(3);
   }
   return 5+random(5);
   //if failed, can't use for a while.
}
