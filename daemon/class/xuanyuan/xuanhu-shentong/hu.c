// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        string msg;
        int damage, ap, dp;
          if(me->query("family/family_name") != "轩辕古墓")
        return notify_fail("你不是狐狸！\n");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
               return notify_fail("你要对谁施展「狐假虎威」？\n");

        if((int)me->query("mana") < 25+(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

      if( me->query_skill("xuanhu-shentong", 1) < 30 )
                return notify_fail("你的玄狐神通等级不够。\n");
 
        if((int)me->query("sen") < 10 )
              return notify_fail("你无法集中精力唤出飞虎！\n");

        me->add("mana", -2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 60);

        if( random(me->query("max_mana")) < 50 ) {
                write("你失败了！\n");
                return 1;
        }

        msg = HIC
"$N念念有词，突然表情变得十分诡秘，就在这时只听到一声震耳欲聋\n"
 "的声音，一只恶虎张开张开血盆大口向$n扑了过来…\n" NOR;

        ap = me->query_skill("spells");
        ap = ( ap * ap * ap / (4 * 400) ) * (int)me->query("sen");
        ap += (int)me->query("combat_exp");
        dp = target->query("combat_exp");
        if( random(ap + dp) > dp ) {

     damage = me->query("max_mana")/15+2*random((int)me->query("mana_factor"));
       
        if( damage > 0 ) {
                msg += HIR "结果$n躲闪不急，被$N咬得血头血脸。\n" NOR;
                        target->receive_damage("sen", damage, me);
                        target->receive_wound("sen", damage/3, me);
                        target->receive_damage("kee", damage, me);
                        target->receive_wound("kee", damage/4, me);
                        me->improve_skill("xuanhu-shentong", 1, 1);
                }
       else {
                        msg += HIC "结果一个闪身，便让了过去！\n" NOR;
                        damage -= (int)target->query("mana_factor");
                        damage -=random((-damage*(int)target->query_skill("spells"))/100);
                        me->receive_damage("sen", -damage, target);
                        me->receive_wound("sen", -damage/3, target);

                        me->receive_damage("kee", -damage, target);
                        me->receive_wound("kee", -damage/4, target);
       }
             }
   else
                msg += "但是被$n躲开了。\n";

        message_vision(msg, me, target);
        if( damage > 0 ) COMBAT_D->report_status(target);
        else if( damage < 0 ) COMBAT_D->report_status(me);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else
                target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        me->start_busy(1+random(2));
        return 3+random(5);
}
