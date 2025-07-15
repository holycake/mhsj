// by gslxz@mhsj 2001/9/6
// fengkuang.c 【疯狂一钯】
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string str;
        object weapon;
                
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(WHT"你要对谁施展这"HIR"[疯狂一钯]"NOR WHT"？\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIR"[疯狂一钯]"NOR WHT"只能在战斗中使用！\n"NOR);

        if((int)me->query("force") < 500 )
                return notify_fail("你的内力不够！\n");

        if((int)me->query("kee") < 300 )
                return notify_fail("你的气血不足，没法子施用外功！\n");

        if((int)me->query_skill("skyriver-rake", 1) < 150)
                return notify_fail("你的天河钯法级别还不够，使用这一招会有困难！\n");

        if((int)me->query_skill("tianpeng-force", 1) < 150)
                return notify_fail("你的天蓬心法级别还不够，使用这一招会有困难！\n");

        me->delete("env/brief_message");

        message_vision("\n只见$N使出了天蓬府绝招"HIR"[疯狂一钯]"NOR"～～～" YEL"绝杀三式"NOR"\n", me);


        me->set_temp("fengkuang_per", 6);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            第      一      式\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            第      二      式\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        message_vision("\n"BLINK HIY"            第      三      式\n"NOR, me);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("fengkuang_per");

        me->receive_damage("kee", 50);
        me->add("force", -100);

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
         if( !userp(target) ){
               if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0) )  
                       { str=target->name()+HIM"被"+me->name()+HIM"用天蓬府绝招"HIW"「疯狂一钯」"HIM"杀死了，听说尸体上已经遍布露骨的钯痕！";
//	                 message("channel:rumor",HIM"〖无中生有〗某人："+str+"\n"NOR,users());
	               }
}else{               if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0) )  
                       {str=target->name()+HIM"被"+me->name()+HIM"用天蓬府绝招"HIW"「疯狂一钯」"HIM"杀死了，听说尸体上已经遍布露骨的钯痕！";
                message("channel:rumor",HIM"〖无中生有〗某人："+str+"\n"NOR,users());
	               }
}

        me->start_busy(2);
        return 1;
}

