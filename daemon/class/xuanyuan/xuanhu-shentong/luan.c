// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
// mihun.c 迷魂术
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
   string msg;
   int success, ap, dp, ap2, ap3, ap4, dp2, dp3, dp4,howlong;

       if( (string)me->query("gender") !="女性")
       return notify_fail("你非为纯阴之身,怎能知哓女儿家的心思??\n");

   if( !target ) target = offensive_target(me);

   if((int)me->query_skill("spells") < 100 || (int)me->query_skill("xuanhu-shentong",1) < 60)
     return notify_fail("你还没学会迷魂术。。。\n");

   if( !target
   ||      !target->is_character()
   ||      target->is_corpse()
   ||      target==me)
     return notify_fail("你想迷谁的魂？\n");  

   if(target->query_temp("no_move"))
   return notify_fail(target->query("name")+"已经魂不守舍，呆若木鸭了！\n");  

   if((int)me->query("mana") < 200 )
     return notify_fail("你的法力不够！\n");

   if((int)me->query("sen") < 10 )
     return notify_fail("你无法集中精力！\n");

   me->add("mana", -200);
   me->receive_damage("sen", 10);

   msg = HIC
"$N娉娉婷婷的走向$n，轻舒玉臂将$n揽在怀里！\n" 
NOR;

   success = 1;
   ap = me->query_skill("spells");
   ap = ap * ap * ap /12 ;
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
   ap2 = (int)me->query_per();
   dp2 = (int)target->query_per();
   ap3 = (int)me->query("mana");
   dp3 = (int)target->query("mana");
 if( (string)target->query("gender") !="男性") 

{if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+4000*dp2+400*dp3) )
     success = 0;}
if( (string)target->query("gender") =="男性")
{if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2000*dp2+200*dp3) )
        success = 0;}
 
  if(success == 1 ){
     msg +=  HIB "$n乍入软玉温香，不由的意乱情迷，对周围一切竟浑然不觉！\n" NOR;
     target->set_temp("no_move", 1);
   
     howlong = random((me->query_skill("spells") -105)+1);
     if(howlong>60) howlong=60;
     call_out("free", howlong, target);
   }       
   else {
     msg +=  HIR "$n鄙夷地看了$N一眼，喝道：把脏手拿开！\n" NOR;   
     me->start_busy(2+random(1));        
     target->kill_ob(me);
   } 

   message_vision(msg, me, target);

   return 1;
}

void free(object target)
{
   if (target)
   target->delete_temp("no_move");      
   return;
}

