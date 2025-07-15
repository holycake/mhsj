//longteng.c by yushu@xyj2 2001/7
#include <ansi.h>
inherit SSERVER;
inherit F_DBASE;
void remove_effect(object me);
void remove_effect1(object me);
int perform(object me, object target)
{       
    object weapon;
    int skill,str_amount,attack_amount,armor_amount;
    skill = me->query_skill("dragonfight",1);
    attack_amount=skill+1/7;
    str_amount=skill+1/7;
    armor_amount=skill+1/2;
    weapon = me->query_temp("weapon");
    if( skill > 250 ) {skill=250;}
    if( !target ) target = offensive_target(me);
                if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「龙腾四海」？\n");
 
        if(!me->is_fighting())
                return notify_fail("「龙腾四海」只能在战斗中使用！\n");

        if(me->query("family/family_name")!="东海龙宫")
                return notify_fail("非龙族不能用「龙腾四海」！\n");

        if((int)me->query("max_force") < 1500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("force") < 1500 )
                return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("dragonfight", 1) < 120)
                return notify_fail("你的「龙形搏击」还不够纯熟！\n");
	  
        if(me->query_temp("no_longteng"))
	         return notify_fail("绝招滥使就不灵了！\n");

        message_vision(HIR"\n只见$N使出龙形搏击中的精华一招「龙腾四海」打向$n！\n"NOR, me, target);
  if (random(me->query("combat_exp")) > random((target->query("combat_exp")/2)))
  {
           message_vision(HIW"\n$N回想起龙形搏击中所有招式的精华，顿时$N的脸上显出龙形!\n"NOR, me, target);             
           me->add_temp("apply/attack", attack_amount);  
           me->add_temp("apply/strength",str_amount);    
           me->add("force", -1000); 
           me->receive_damage("sen", 400);
           me->start_busy(1);
           if(me->query_skill("dragonfight", 1) > 139)
           call_out("next", 1, me, target);
	    call_out("longteng_ok",20,me);
           me->set_temp("no_longteng",1);
           me->start_call_out( (: call_other, __FILE__, "remove_effect",me, str_amount,attack_amount:), skill/15);
   }
   return 1;
   }
int next(object me, object target)
{
     if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
     if((int)me->query("force") < 100 )
          return notify_fail("你待要再出第二式，却发现自己的内力不够了！\n");
     if((int)me->query("sen") < 100 )
          return notify_fail("你待要再出第二式，却发现自己的精神不够了！\n");
     message_vision(HIG"\n$N运起龙神心法中的护体神功，顿时$N的身上长出片片龙鳞护身!\n"NOR, me, target);
     me->add_temp("apply/armor", (me->query_skill("dragonfight",1)+1)/2);
     me->start_call_out( (: call_other, __FILE__, "remove_effect1", me, (me->query_skill("dragonfight",1)+1)/2:), (me->query_skill("dragonfight",1)+1)/15);
     me->receive_damage("sen", 100);
     me->add("force", -100);
     if(me->query_skill("dragonfight", 1) > 159)
     call_out("next1", 1, me, target);    
     return 1;
}

int next1(object me, object target)
{
     int targetbusy,skills; 
     skills = me->query_skill("dragonfight",1);
     if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
     if((int)me->query("force") < 100 )
          return notify_fail("你待要再出第三式，却发现自己的内力不够了！\n");
     if((int)me->query("sen") < 100 )
          return notify_fail("你待要再出第三式，却发现自己的精神不够了！\n");
     message_vision(HIC"\n$N身上、脸上的龙鳞和龙形显现顿时镇住了$n!\n"NOR, me, target);
     if ( skills > 140 ) targetbusy=4;
     if ( skills > 200 ) targetbusy=5;	
     target->start_busy(targetbusy);
     me->receive_damage("sen", 100);
     me->add("force", -100);
     if(me->query_skill("dragonfight", 1) > 199)
     call_out("next2", 1, me, target);    
     return 1;
}

int next2(object me, object target)
{
     object weapon;
     weapon = me->query_temp("weapon");  
     if(!living(target)) 
          return notify_fail("对手已经不能再战斗了。\n");
     if((int)me->query("force") < 100 )
          return notify_fail("你待要再出第四式，却发现自己的内力不够了！\n");
     if((int)me->query("sen") < 100 )
          return notify_fail("你待要再出第四式，却发现自己的精神不够了！\n");
     me->delete("env/brief_message");
        target->delete("env/brief_message");
     message_vision(HIR"\n只见$N灌输了「龙腾四海」前三招的力量，使出了最后一招！\n"NOR, me, target);
     COMBAT_D->do_attack(me, target, weapon);
     me->receive_damage("sen", 100);
     me->add("force", -100);
     me->start_busy(3);
     return 1;
}

void longteng_ok(object me)
{ 
      if (!me) return;
      me->delete_temp("no_longteng");
}         
void remove_effect(object me)
{
        me->add_temp("apply/strength", -(me->query_skill("dragonfight",1)+1)/7);
        me->add_temp("apply/attack", -(me->query_skill("dragonfight",1)+1)/7);
        tell_object(me, HIC"「龙腾四海」第一式收式！。\n"NOR);
}
void remove_effect1(object me)
{
       me->add_temp("apply/armor", -(me->query_skill("dragonfight",1)+1)/2);
       tell_object(me, HIB"「龙腾四海」第二式收式！。\n"NOR);
}