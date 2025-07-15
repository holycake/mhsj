inherit SKILL;

string *dodge_msg = ({
        "但是$n身形飘忽，一招「穿云势」拔地而起，一纵一连环，\n越拔越高，几个翻腾，举重若轻地避开了这一击。\n",
        "$n身随意转，一式「破雾势」，全身化作无数虚影，身周隐隐泛出烟霞，\n$N惊异不定间，$n已轻轻掠出丈外。\n",
        "$n身形往上一拔，一招「开天势」，腾空而起，直上云霄，避了开去。\n",
        "$n气聚丹田，一招「劈地势」，身形急退，缩地千里，躲开$N那致命一击。\n",
        "$n大喝一声，运起全身内力推出一招「推山势」，与$N的内劲一触，\n只听“嘭”的一声大响，$n已借势弹开，落在数尺之外。\n",
        "$n身形晃动，一招「搅海势」，全身急旋，化作无数虚影。\n$n越旋越急，劲风呼呼，形成一个旋涡，将$N困入其中难以抽身。\n",
        "$n真气荡漾，一招「惊雷势」，速度提升到极速，化为一道电光，远远退开。\n",
        "$n使出「裂电势」，身形急闪，如电过长空，轻而易举地躲开了$N这一招。\n",
        "$n身影微动，已经藉一招「龙腾势」，身形曲折如龙行，轻轻闪过。\n",
        "$n腾空一跃，双脚向前一踢，一招「虎扑势」，一个倒剪，躲开数尺。\n",
        "只见$n身影一晃，一式「豹跃势」，脚步刁钻，早已避在七尺之外。\n",
        "可是$n使一招「鹰飞势」，身子轻轻飘了开去，早已绕到$N身後！\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}

int valid_learn(object me)
{
        return 1;
}

string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("sen") < 50 )
                return notify_fail("你的精神太差了，不能练天威十二势。\n");
        me->receive_damage("sen", 40);
        return 1;
}

