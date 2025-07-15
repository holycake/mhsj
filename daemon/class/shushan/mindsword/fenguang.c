//modified by vikee for xlqy-zq station
//2000-12-5 9:20
//perform fenguang.
//化去对方内力和法力。

#include <ansi.h>
inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        int mypot,tapot,damage,damage_pot;
        
        weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要化去谁的内力？\n");

              if(!me->is_fighting())
                return notify_fail("你们没有在打架！\n");

        if((int)me->query("max_force") < 400 )
                return notify_fail("你的内功太差。\n");

        if((int)me->query("force") < 200 )
                return notify_fail("你的内力不足！怎能化他人内力？\n");

        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
                
        if((int)me->query("kee") < 100 )
                return notify_fail("你的气血不足，没法子施用外功！\n");
                
 	if((int)me->query_skill("taoism", 1) < 100)
          	return notify_fail("你的仙风云体术等级不够，施这招恐怕有困难！\n");
        
        if((int)me->query_skill("mindsword",1) < 100)
                return notify_fail("你的剑法火候还不到，使用这一招会有困难！\n");
          
	//as followed was modified by vikee
	mypot=(int)me->query_skill("sword");
	mypot=mypot*mypot*mypot/10 + random( (int)me->query("combat_exp"));
	
        tapot=((int)target->query_skill("dodge")+(int)target->query_skill("parry"))/2;
        tapot=tapot*tapot*tapot/10 + random( (int)target->query("combat_exp"));      
        
        damage_pot=(int)me->query_skill("mindsword");           
                  
        me->delete("env/brief_message");
	target->delete("env/brief_message");
	message_vision(HIW"\n$N如痴如狂，口中喃喃自语：\n",me,target);
	message_vision(HIW"\n挫其锐，解其纷，和其光，同其尘。\n",me,target);
	message_vision(HIW"\n手中剑光一闪，掠向$n\n"NOR,me,target);
	
	
	if ( random( mypot + tapot ) > tapot )	
	{     	
     	message_vision(HIR"\n$n脚下一个不稳，踉跄几步，呕出几口鲜血，面色苍白了许多！\n"NOR,me,target);
          
          damage=damage_pot+random(damage_pot)*2; 
          //如果一个mindsword=200的player化解的内力范围是200-600.          
          
	    target->add("force",-damage);
            if ((int)target->query("force")<0)
             {
             	target->set("force",0);
		message_vision(HIR"$n的内力被化净，已无伏鸡之力！\n"NOR);
	     }
	
	     target->add("mana",-damage);
	     
	     if ((int)target->query("mana")<0)
	     {
	     	target->set("mana",0);
	     	message_vision(HIR"$n的法力被化净，已无伏鸡之力！\n"NOR);
	     }
           	//施功者消耗一定的内力和法力和100 pot 的精神作为代价。
           	me->add("force", -random(damage/2));  
           	me->add("mana",-random(damage/2));
           	me->receive_damage("sen", 100);
           	           	         
           	if ((int)me->query("force")<0) me->set("force",0);
	
        }
        
        else 
     	message_vision(HIY"\n$n身形一晃，躲过了$N的攻击。\n"NOR,me,target);
        
           if( !target->is_fighting(me) )
            {
                if( living(target) ) 
                {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
            }
        me->start_busy(1+random(1));
        return 1;
}

   
