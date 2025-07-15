#include <ansi.h>

inherit SSERVER;

int cast(object me, object target)
{
        int success_adj, damage_adj;

        success_adj = 140;
        damage_adj = 130;
 

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁用这[禁千贰百拾壹式.八稚女]？\n");

        if((int)me->query("mana") < 25+2*(int)me->query("mana_factor") )
                return notify_fail("你的法力不够！\n");

        if((int)me->query("sen") < 20 )
                return notify_fail("你无法集中精力！去送死吗？\n");

        me->add("mana", -25-2*(int)me->query("mana_factor"));
        me->receive_damage("sen", 10);

        if( random(me->query("max_mana")) < 50 ) {
                write("你很奇怪为什么法术不灵了？\n");
                return 1;
        }

        SPELL_D->attacking_cast(
                me, 
                        //attacker 
                target, 
                        //target
                success_adj,    
                        //success adjustment
                damage_adj,     
                        //damage adjustment
                "both",                 
                        //damage type: could be "qi"/"kee", "shen"/"sen", ...default "both"
                HIG "$N口中念了几句咒文，"NOR""BLINK HIR"[禁千贰百拾壹式.八稚女]"NOR""HIG",一个影子从$N后穿出,风一般的奔向$n...\n" NOR,
                        //initial message
                HIY "一阵狂风袭来,$n被影子抓住,“砰”的巨响,$n被炸飞了!\n" NOR, 
                        //success message
                HIW "但是$n静心默念法术，竟不为所动.\n" NOR, 
                        //fail message
                HIR "但是影子却失去了控制，不由间在$N身后爆炸了!\n" NOR, 
                        //backfire initial message
                HIY "一阵狂风袭来,$n被影子抓住,“砰”的巨响,$n被炸飞了!\n" NOR
                        //backfire hit message. note here $N and $n!!!
        );

        me->start_busy(1+random(2));
        return 3+random(5);
}

