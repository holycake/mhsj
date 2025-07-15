
#include <ansi.h>

inherit SSERVER;

int perform(object me)
{
        string msg;
        object target;
        int skill, ap, dp, force_wound, kee_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("tianyi-zhen",1);

        if( !(me->is_fighting() ))
                return notify_fail("「斩尽杀绝」只能在战斗中用在对手身上。\n");

        message_vision("有到这。", me, target);
        /*if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "unarmed")*/

        if( skill < 70)
                return notify_fail("你的天一神针不够纯熟, 不能使用「斩尽杀绝」！\n");

        if( me->query("force") < 150 )
                return notify_fail("你的内力不够，无法运用「斩尽杀绝」！\n");

        msg = HIY "$N并指入刀，指缝间夹着三枚暗器,潜运内力，一式「斩尽杀绝」，直奔
$n的上、中、下丹田打去。\n";
        message_vision(msg, me, target);

        ap = me->query_skill("unarmed",1) + skill;
        dp = target->query_skill("force") / 2;
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp )
        {
                if(userp(me))
                        me->add("force",-100);
                msg = "$N一招「斩尽杀绝」正中对手，$n只觉得象汽球被刺破一般\n";
                msg += "全身气血释放无遗！\n" NOR;


                force_wound = 500 + random(skill);
                if(force_wound > target->query("force"))
                        force_wound = target->query("force");

                kee_wound = force_wound / 5;
                if(kee_wound > target->query("kee"))
                        kee_wound = target->query("kee");

                target->add("force", -force_wound);
                target->add("kee", -kee_wound);
                target->add("eff_kee", -kee_wound);
                target->start_busy(2);
              me->start_busy(random(2));
        }
        else
        {
                if(userp(me))
                        me->add("force",-80);
                msg = "可是$n轻轻一闪，躲过了这致命的一招。\n"NOR;
                me->start_busy(2);
        }
        message_vision(msg, me, target);

        return 1;
}
