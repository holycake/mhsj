// sword.c

inherit SKILL;
#include <ansi.h>;

void skill_improved(object me)
{
    int m_skill = me->query_skill("makeup", 1);

    if (m_skill >= 100 && m_skill % 10 == 0) {
        tell_object(me, HIM"你潜心修习养颜之术，日久功深，神清气朗，仪态自华。\n"NOR);
        tell_object(me, HIM"气质由心而发，映于眉宇之间，容貌因此更胜往昔。\n"NOR);
        me->add("per", 1);
    }
}