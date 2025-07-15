
// 乾坤无际
// edit by gslxz@mhsj 10/16/2001  可以加上门派限制

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        string str;
        int extra;
        object weapon;
        extra = me->query_skill("qianjun-bang",1);

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "stick")
                        return notify_fail("你使用的武器不对。\n");
        
        if( !target ) target = offensive_target(this_player());
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
               return notify_fail(HIR"「乾坤无际」"NOR"只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if(extra < 120)
            return notify_fail("你的千钧棒法还不够纯熟！\n");
     if(me->query("family/family_name")!="方寸山三星洞")
           return notify_fail(HIY"“乾坤无际”只有方寸山三星洞门人才可以用！\n"NOR);
        if(me->query("max_force") < 500)
            return notify_fail("你的内力还不够，不要勉强了！\n"); 
        if(me->query("force") < 1000)
            return notify_fail("你的真气不够，不要勉强了！\n"); 
              
        
        if(extra >= 400)  extra = 400;
        
        me->add_temp("apply/attack",extra/3);
        me->add_temp("apply/damage",extra/3);
        me->add_temp("apply/strength", extra/10);
        message_vision(HIY"$N将全身真气集中到手中的"+weapon->query("name")+ HIY"上面，对着$n使出了
 菩提祖师的独门绝招「乾坤无际」！"NOR,me,target);
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,str);
         message_vision(HIR  "$N全身真气外放，衣衫冉冉飘动，双眸倏转妖红！！" NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,str);
 message_vision(HIR  "$N手中"+weapon->query("name")+ HIR"内所有阳气已是内燃敛收，放出肉眼难以直视的青白光华！" NOR,me,target);
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,str);

    if (target->query("eff_kee")<0 || (!living(target) && target->query("kee")<0))  
                       {str=target->name()+HIM"被"+me->name()+HIM"用方寸山三星洞绝招"HIW"「乾坤无际」"HIM"杀死了，听说全身骨骼尽断而亡！";
	                 message("channel:rumor",HIM"〖无中生有〗某人："+str+"\n"NOR,users());
	               }
 me->add_temp("apply/attack",-extra/5);
        me->add_temp("apply/damage",-extra/5);
        me->add_temp("apply/strength", -extra/15);

        me->start_busy(2);
        return 1;
}
