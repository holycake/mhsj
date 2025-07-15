void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
        string msg;
        int myexp,yourexp,mystr,yourstr,lvl,lv;
        object weapon;

        if( !target ) target = offensive_target(me);

        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "spear"  )
                return notify_fail("你必须在使用兵器时才能使[火龙摆尾」！\n");
        if( me->query_skill("huoyun-qiang",1) < 80 )
                return notify_fail("你的火云枪级别不够使用［火龙摆尾］\n");
         if (me->query_skill_mapped("force")!="huomoforce")
                return notify_fail("火龙摆尾必须配合火魔心法才能使用。\n");
           if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［火龙摆尾］只能对战斗中的对手使用。\n");
        weapon = target->query_temp("weapon");
        if(!objectp(weapon)) return notify_fail("你的对手没有用兵器！\n");
        myexp = (int) me->query("combat_exp")/1000;
        mystr = (int) me->query("str");
        yourexp = (int) target->query("combat_exp")/1000;
        yourstr = (int) target->query("str");

        lv  = (int) me->query_skill("spear") ;
        lvl = (int) target->query_skill("dodge")+1;
   msg = YEL "$N双手抡起棍子往下一砸，$n的兵器断成两截落在了地下！ \n" NOR;
if(objectp(weapon) )
{
        if( random(myexp * lv * mystr) > (yourexp * yourstr *lvl)/3)
                
        {
                weapon->unequip();
                weapon->move(environment(target));
                weapon->set("name","断成两截的"+weapon->query("name"));
                weapon->set("no_get",1);
                weapon->set("long","一件断成两截的"+weapon->query("name"));
	call_out("remove_broken_weapon", random(30)+60,weapon);
                message_vision(msg, me, target);
                target->start_busy(2);
        }
        else
        {
     msg=YEL"结果$n看破了$N的企图轻巧地躲过，而$N用力过度，闹了个手忙脚乱。\n"NOR;
                message_vision(msg, me, target);
                COMBAT_D->do_attack(target,me, weapon, TYPE_REGULAR);
        }
                me->start_busy(2);
}
        return 1;
}
