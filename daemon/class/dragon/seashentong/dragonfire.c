
#include <ansi.h>
inherit SSERVER;
int cast(object me, object target)
{
   string msg;
   object *inv, ob;
   int damage, equip, ap, dp;
   if( !target ) target = offensive_target(me);
   if( !target
   ||   !target->is_character()
   ||   target->is_corpse()
   ||    target==me)
     return notify_fail("你要对谁喷龙神怒火？\n");
      inv = all_inventory(target);
      if( sizeof(inv) == 0)
      return notify_fail("对方身上好象没什么东西可以让你烧了!!\n");

   if((int)me->query_skill("seashentong", 1) < 80 )
     return notify_fail("你的碧海神通火候不够，哪里喷得出真火！\n");
   if((int)me->query("mana") < 40+(int)me->query("mana_factor") )
     return notify_fail("你的法力不够，喷出的真火恐怕没有什么用！\n");

   if((int)me->query("force") < 200 )

     return notify_fail("你的内力不够，无法将真火喷出。\n");

   if((int)me->query("sen") < 40 )
     return notify_fail("你现在神智不清，别把自己烧伤了！\n");

   me->add("mana", -50-(int)me->query("mana_factor"));
   me->add("force", -100);
   me->receive_damage("sen", 50);

   if( random(me->query("mana")) < 150 )
  {
     write("这一次好象不灵。\n");
     return 1;
   }

msg = RED
"$N怒气上涌，摇身一变，变成一条巨龙，长达数十丈，煞是威猛!\n\n"
"这时$N突然把嘴一张，突出一股神火，向$n烧去!\n\n"NOR;

   ap = me->query_skill("spells");
   ap = ( ap * ap * ap / (9 * 400) ) * (int)me->query("sen");
   ap += (int)me->query("combat_exp");
   dp = target->query("combat_exp");
    if( random(ap) > dp )
   {
        inv = all_inventory(target);
        if( sizeof(inv) == 0)
        return notify_fail("对方身上好象没什么东西可以让你烧了!!\n");
       message_vision(msg, me, target);
        ob = inv[random(sizeof(inv))];
message_vision(HIR"只见火焰一舔，$N身上的$n"+HIR"已经被烧焦了。"NOR,target,ob);
        destruct(ob);
        me->improve_skill("seashentong", 1, 1);
   }
   else {
     msg += "但是被$n躲开了。\n";
   message_vision(msg, me, target);}
   if( damage > 0 ) COMBAT_D->report_status(target);
 if( !target->is_fighting(me) )
   {
     if( living(target) )
     {
        if( userp(target) ) target->fight_ob(me);
        else target->kill_ob(me);
     }
     me->kill_ob(target);
   }

   me->start_busy(1+random(2));
   return 3+random(5);
}

