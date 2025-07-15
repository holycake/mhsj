// feisha.c

#include <ansi.h>

// #define SPELL_D "/adm/daemons/spelld"

inherit SSERVER;

int cast(object me, object target)

{

 int success_adj, damage_adj;

 success_adj = 110;

 damage_adj = 100;

 if( !target ) target = offensive_target(me);

 if( !target

 ||      !target->is_character()

 ||      target->is_corpse()

 ||      target==me)

  return notify_fail("你要对谁施展飞沙走石？\n");

 if((int)me->query("mana") < 100+2*(int)me->query("mana_factor") )

  return notify_fail("你的法力不够！\n");

 if((int)me->query("sen") < 100 )

  return notify_fail("你无法集中精神！\n");

 me->add("mana", -25-2*(int)me->query("mana_factor"));

 me->receive_damage("sen", 50);

 if( random(me->query("max_mana")) < 150 ) {

  write("你失败了！\n");

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

  HIC "\n$N突然腾空而起，口中高呼风 雨 雷 电，以太阴之力带动草木向$n卷去！\n

" NOR,

   //initial message

  HIR "\n结果$n被吹得分不清东南西北！\n" NOR,

   //success message

  HIC "\n$n屹立风中，巍然不动。\n" NOR,

   //fail message

  HIC "沙木草石被$n的法力一逼，反向$N卷去！\n" NOR,

   //backfire initial message

  HIC "结果$n被吹得分不清东南西北！\n" NOR

   //backfire hit message. note here $N and $n!!!

 );

 me->start_busy(1+random(2));

 return 3+random(5);

}

