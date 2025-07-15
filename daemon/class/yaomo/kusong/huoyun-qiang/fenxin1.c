//Cracked by Roath
//Jiz
#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
	object *inv, obj;
	int i, mypot,tapot,temp_dodge,temp_spells;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail(HIR"你要对谁施展这一招「烈火焚心」？\n"NOR);

        if(!me->is_fighting())
                return notify_fail(HIR"「烈火焚心」只能在战斗中使用！\n"NOR);

        if((int)me->query("max_force") < 200 )
                return notify_fail("你的内力不够！\n");

	if((int)me->query("force") < 200 )
		return notify_fail("你的内力不足！\n");

        if((int)me->query("sen") < 200 )
                return notify_fail("你的精神不足，没法子施用外功！\n");

        if((int)me->query_skill("huoyun-qiang", 1) < 110)
                return notify_fail("你的火云枪级别还不够，使用这一招会有困难！\n");

message_vision(HIR"\n$N运足精神，对着$n喷出了熊熊烈火！\n"NOR, me, target);

	mypot=(int)me->query_skill("spear");
	mypot=mypot*mypot*mypot/10 + (int)me->query("combat_exp");

	tapot=(int)target->query_skill("parry");
	tapot=tapot+(int)target->query_skill("dodge")/10;
	tapot=tapot*tapot*tapot/10 + (int)target->query("combat_exp");

//	write("mypot " + mypot + ", tapot " +tapot+ "\n");

	if( random( mypot+tapot ) > tapot ) {

		inv = all_inventory(target);
		i = sizeof(inv);

		if ( i < 1 ) {
			message_vision(HIR"$N躲闪不及，被打个正着！\n"NOR, target);
			target->receive_damage("kee",
random((int)me->query("max_force")/50+(int)me->query("force_factor")));
			COMBAT_D->report_status(target);
		} else {
			if(target->query_temp("armor")||target->query_temp("weapon")) {
				if( target->query_temp("armor") ) {
 				        for (i=0; i < sizeof(inv); i++ ) {
						obj = inv[i];
						if( obj->query("equipped") != "worn" ) continue;
						obj->delete("equipped");
						obj->set("value", 0);
						obj->set("No_Wear", 0);
						message_vision(HIR"$N"HIR"身上的$n"HIR"被烈火烧成了碎片！\n"NOR, target,obj);
						//here is added by vikee 2000-12-2 0:59
						//防止break后有效轻功和法术不消失.
						temp_dodge=(int)obj->query("armor_prop/dodge",1);
						temp_spells=(int)obj->query("armor_prop/spells",1);
						if (temp_dodge)
						target->add_temp("apply/dodge",-temp_dodge);
						if (temp_spells)
						target->add_temp("apply/spells",-temp_spells);
												
						obj->set("name", obj->query("name")+"的碎片");
						call_out("remove_broken_cloth",random(300)+60,obj);
						obj->move(environment(target));
					}
				}
/*
				if (target->query_temp("weapon")) {
					obj=target->query_temp("weapon");
					obj->unequip();
					obj->set("value", 0);
					message_vision(HIW "只听见「啪」地一声，$N手中的" + obj->name()+ "已经断为两截！\n" NOR, target);
					obj->set("name", "断掉的" + obj->query("name"));
					obj->set("weapon_prop", 0);
	                		obj->set("armor_prop", 0);	                		          		
					obj->move(environment(target));
					call_out("remove_broken_cloth",random(300)+60,obj);
				}

			target->delete_temp("armor");
			target->delete_temp("apply");
			} else {
				message_vision(HIR"$N躲闪不及，被汹汹的烈火包围着！\n"NOR, target);
                       		target->receive_damage("kee",
random((int)me->query("max_force")/50+(int)me->query("force_factor")));
                       		COMBAT_D->report_status(target); 
*/			}
		}
	} else {
	message_vision(RED"却被$N躲开了！\n"NOR, target);
	}
        me->add("force", -150);
	me->receive_damage("sen", 50);

	target->kill_ob(me);

        me->start_busy(1+random(2));
        return 1+random(5);
}

void remove_broken_cloth(object obj)
{
  if(obj && environment(obj)) {
    tell_object(environment(obj),
      "一阵微风吹过，"+obj->name()+"化为片片尘土，消失不见了。\n");
    destruct(obj);
  }
}
