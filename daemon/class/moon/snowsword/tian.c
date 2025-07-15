#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        string str;
        int snowsword,moonforce,moondance,ini_damage_apply,damage;
   string desc_msg="";
  int sword_level;
        
        snowsword = (int)me->query_skill("snowsword", 1);
        moonforce = (int)me->query_skill("moonforce", 1);
        moondance = (int)me->query_skill("moondance", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「漫天飞雪」？\n");

        if(!me->is_fighting())
                return notify_fail("「漫天飞雪」只能在战斗中使用！\n");
        
        
        sword_level=(int)(snowsword/50);
        if( snowsword < 50)
                return notify_fail("你的风回雪舞剑法级别还不够，使用这一招会有困难！\n");

        if(me->query("family/family_name") != "月宫")
                return notify_fail("[漫天飞雪]是月宫不传之密！\n");
        
        if( moonforce < 50)
                return notify_fail("你的圆月心法修为不够，使用这一招会有困难！\n");
        
        if( moondance < 50)
                return notify_fail("你的冷月凝香舞级别还不够，使用这一招会有困难！\n");
                
        if( me->query("force_factor") > 0)
                return notify_fail("「漫天飞雪」绝技重招不重力。加力出招怎能剑走轻灵？\n");
        
        if( time()-(int)me->query_temp("wuxue_end") < 5 )
                return notify_fail("绝招用多就不灵了！\n");
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "百";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动幻作漫天飞雪卷向$n。\n"NOR,me,target);
        damage=1;
        //前三剑
        message_vision(HIC"\n$N同时使出风回雪舞剑的前三招，在半空中压向$n。\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",100);
        me->set_temp("WX_perform", 0);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) {me->add_temp("apply/damage",100);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 6);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //再两剑
        if( snowsword > 99 && moonforce > 99 && moondance > 99 )
            {
            	message_vision(HIC"\n$N身体斜斜向上飘出，也不回头，反手就刺出了两招。\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 7);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) {me->add_temp("apply/damage",100);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 8);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
              }
      
           //最后两剑
           if( snowsword > 149 && moonforce > 149 && moondance > 149 )
               {
               	    message_vision(HIC"\n$N斜斜一再个翻身，长剑幻作千百支冰箭，夹着一股寒风扑向$n。\n"NOR,me,target);
               	    
               	    if (damage < 1) {me->add_temp("apply/damage",100);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 9);
                    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
      
                     if (damage < 1) {me->add_temp("apply/damage",300);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 10);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
            
                     if (target->query("eff_kee")<0 || !living(target))  
                        {str=target->name()+HIM"被"+me->name()+HIM"用月宫绝招"HIW"「漫天飞雪」"HIM"杀死了。听说尸体上有"+desc_msg+"十多道深可见骨的伤痕！";
                          message("channel:rumor",HIM"〖无中生有〗某人："+str+"\n"NOR,users());
	               }
	          }
	                
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

        me->set_temp("wuxue_end",time());
        return 1;
}

