//Cracked by Roath
// bugong.c 霸王枪法之不攻
// writted by libai
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string msg;
        object weapon;
        int i , mkee;
        
        int b_time = (int)me->query_skill("bawang-qiang") / 40 + (int)me->query_skill("yanxing-steps") / 40;
        if (b_time < 4) b_time = 4;
        if (b_time > 8) b_time = 8; 

        if( !target ) target = offensive_target(me);

        
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "spear")
           return notify_fail("你没用枪，怎么使出不攻！\n");
        
        if (me->query("force") < 200) return notify_fail("你的内力太少。\n");
        
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不攻只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "还在犹豫不决，放胆攻击吧。\n");
                
        if(me->query("family/family_name") != "将军府" )
                return notify_fail("你是哪儿偷学来的武功，也想用不攻！\n");

        if( (int)me->query_skill("lengquan-force", 1) < 60 )
                return notify_fail("你的冷泉心法还差些火候。\n");
        if( (int)me->query_skill("yanxing-steps", 1) < 80 )
                return notify_fail("你的雁行步法无法配合不攻。\n");
        if( (int)me->query_skill("bawang-qiang", 1) < 80 )
                return notify_fail("你的霸王枪法不够娴熟，不能采用不攻。\n");

        msg = CYN "$N手中"RED"长枪"CYN"猛抖，脚踏奇步，登时涌起凛冽杀气，遥罩$n，似攻非攻，似守非守!
"HIR"不攻"CYN"一出，$n立时感到若不主动进攻，将陷於被动挨打的劣势。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")*3/5 ) {
                msg += "$n连忙上前猛攻,但是却无从着手，不由陷入了两难的境地。\n" NOR;
                target->start_busy(b_time);
        } else {
                me->start_busy(4);
                msg += "可是$n也并不着急,反而收起兵刃急退数步。\n" NOR;
        }

        message_vision(msg, me, target);
        me->add("force",-200);
        return 1;
}
