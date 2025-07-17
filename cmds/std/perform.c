// perform.c
#include <skill.h>
#include "/cmds/std/valid_kill.h";

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object weapon, target;
    string martial, perf, mapped_skill;
    int result;

    seteuid(getuid());

    if( me->is_busy() )
        return notify_fail("( 你上一个动作还没有完成，不能施用外功。)\n");

    if( !arg ) return notify_fail("你要用外功做什么？\n");

    if ( !wizardp(me) && environment(me)->query("no_fight")) 
        return notify_fail("这里不能施用外功。\n");

    // 支持 perform xxx on someone
    if( sscanf(arg, "%s on %s", perf, arg)==2 ) {
        target = present(arg, environment(me));
        if( !target ) target = present(arg, me);
        if( !target ) return notify_fail("这里没有 " + arg + "。\n");

        if(!valid_kill(me,target,0)) return 0;

        if( userp(me) && userp(target) && target->query_temp("netdead") )
            return notify_fail("对方正在断线中，不能对其施用外功。\n");

        arg = perf + " " + arg;
    } else if(sscanf(arg, "%s %s", perf, arg)==2 ) {
        // fallback
        arg = perf;
    }

    // 获取武器类型（如 sword、blade、unarmed）
    if( weapon = me->query_temp("weapon") )
        martial = weapon->query("skill_type");
    else
        martial = "unarmed";

    // 获取该类型所 enable 的特殊技能名（如 sword -> lingxu-jian）
    mapped_skill = me->query_skill_mapped(martial);

    // 优先尝试当前武器/武学类型的 enable 技能模块
    if( stringp(mapped_skill) ) {
        result = SKILL_D(mapped_skill)->perform_action(me, arg);
        if( result ) {
            if( random(120) < me->query_skill(mapped_skill) )
                me->improve_skill(martial, random( (int)me->query_skill("force", 1)*10), 1);
            me->improve_skill(mapped_skill, random( (int)me->query_skill("force", 1)*10), 1);
            return 1;
        }

        // 如果当前使用的不是空手，则尝试空手技能 fallback
        if (martial != "unarmed") {
            string arm_skill = me->query_skill_mapped("unarmed");
            if (stringp(arm_skill)) {
                result = SKILL_D(arm_skill)->perform_action(me, arg);
                if (result) {
                    if (random(120) < me->query_skill(arm_skill))
                        me->improve_skill("unarmed", random( (int)me->query_skill("force", 1)*10), 1);
                    me->improve_skill(arm_skill, random( (int)me->query_skill("force", 1)*10), 1);
                    return 1;
                }
            }
        }

        // 不覆盖原技能模块的提示信息
        return 0;
    }

    // mapped_skill 是空的（未 enable）
    return notify_fail("你请先用 enable 指令选择你要使用的外功。\n");
}

int help (object me)
{
        write(@HELP
指令格式：perfrom [<武功种类>.]<招式名称> [<施用对象>]

如果你所学的外功(拳脚、剑法、刀法....)有一些特殊的攻击方式或招式，可以
用这个指令来使用，你必须先用 enable 指令指定你使用的武功，不指定武功种
类时，空手的外功是指你的拳脚功夫，使用武器时则是兵刃的武功。


换句话说，只要是 enable 中的武功有特殊招式的，都可以用这个指令使用。
HELP
        );
        return 1;
}
