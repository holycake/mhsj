#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        int delay, myhand;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不在战斗中，露什么破绽？\n");

        myhand=(int)me->query_skill("iori-kuihua",1);
        if(myhand>160) myhand=160; // mon 12/7/98
        if(myhand<50) 
                return notify_fail("你的[百贰拾七式.葵花]不够级别，再萧风也无用。\n");

        delay=myhand/16;

        if( target->is_busy() )
                return notify_fail(target->name() + "已经被你一把掌打的晕头转向了\n");

        msg = HIB "$N的招式突然一变，"BLINK""HIR"萧风"NOR""HIB"..$N一声狂叫,一只手惑的伸了出去\n"NOR;
        //change totoal random to half random half ur own value to make the sucessrate more stable
        if( ((random(me->query("combat_exp"))*3/4 + (me->query("combat_exp")/4) > (int)target->query("combat_exp")*5/8 ))) {
                msg += RED"$n被一把掌打的晕头转向，辩不清南北\n"NOR;
                msg += HIB"结果$p被$P打了个措手不及！\n" NOR;
                target->start_busy(delay);
                me->start_busy(random(2));
        } else {
                msg += "可是$p看破了$P的企图，并没有被抓住。\n" NOR;
                me->start_busy(2+random(1));
        }
        message_vision(msg, me, target);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
                me->kill_ob(target);
        }

        return 1;
}

