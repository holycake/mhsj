#include <skill.h>
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("五瘟符", ({"poison seal", "seal", "paper"}));
	set_weight(100);
	if(clonep())
    		set_default_object(__FILE__);
  	else {

        set("long","一张画上了符咒的桃符纸，中央有个大大的“瘟”字。\n");
        set("unit", "张");
        set("value", 0);
	set("no_put",1);
	set("no_sell",1);
	}
	setup();
}

void init()
{

  object me = this_object();
  object where = environment();

  if (userp(where))
  {
    if (me->query("owned"))
    {
      if (me->query("owned")!=where->query("id"))
      {
        call_out("destruct_me",1,where,me);
      }
    }
    else
    {
      me->set("owned",where->query("id"));
    }
  }
}

void destruct_me(object where, object me)
{
        object seal;
        if( seal=new("/obj/paper_seal"))
                seal->move(where);
	message_vision("$N手中的$n突发红光，符咒渐渐淡去不见了。\n",where,me);
        destruct(me);
}

void invocation(object who)
{
	int i,a,b,c;
	
	a=who->query("daoxing");
	b=(int)who->query_skill("spells")*(int)who->query_skill("spells")*(int)who->query_skill("spells");
	c=(int)who->query("mana_factor")*(int)who->query("mana_factor")*(int)who->query("mana_factor");
	i=a+b+c;

	this_object()->set("ap",i);
	return;
}
int ji_ob(object victim)
{
	object seal=this_object();
	object me=this_player();
	object where=environment(me);

	int damage, ap, dp, i;
	
	if(me->is_busy())
		return notify_fail("你正忙着呢，无法祭五瘟符。\n");
	if( !victim)
		return notify_fail("你想祭的人不在这里。\n");
	if( where->query("no_magic"))
		return notify_fail("这里不能祭五瘟符。\n");
	if( !me->is_fighting())
		return notify_fail("只有战斗中才能祭五瘟符。\n");
	if( (int)me->query("mana") < 100 )
		return notify_fail("你的法力不能控制五瘟符。\n");
	if( (int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，很难驾驭五瘟符。\n");


	message_vision(HIC"\n$N大喊一声“着”，手一挥，祭出了一张$n。。。\n"NOR, me, seal);
message_vision(HIC"$n「呼」地一下飞到半空，红光闪后化为一阵飞雨，雹打残荷般向$N袭去。\n"NOR,
victim,seal);



	ap= (int)seal->query("ap");
	dp= (int)victim->query("daoxing")+(int)victim->query("combat_exp");
	dp+= (int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_skill("dodge")*(int)victim->query_kar()/20;


	if(random(ap+dp) > dp)	{

                damage = (int)me->query("max_mana") / 20 +
random((int)me->query("eff_kee") / 15);
                damage -= (int)victim->query("max_mana") / 20 +
random((int)victim->query("eff_kee") / 15);                                 
                damage+=(int)me->query("mana_factor")-random((int)victim->query("mana_factor"));
	
		if( damage> 0){
	message_vision(HIC"\n$N躲闪不及，被溅了一身。。。\n"NOR,victim);
		i=damage/20;
		if( i > 20){i=20;}
		if( i < 5 ){i=5;}
		victim->apply_condition("jjf_poison",
(int)victim->query_condition("jjf_poison")+i);
		} else {
			message_vision(HIC"\n$N猛退几步，躲了过去。\n"NOR,victim);
		}
	}else{
		message_vision(HIC"\n谁知被$N躲了过去。\n"NOR,victim);
	}
	
	        if( !victim->is_fighting(me) ) {
                if( living(victim) ) {
                        if( userp(victim) ) victim->fight_ob(me);
                        else
				victim->kill_ob(me);
                }
                me->kill_ob(victim);
        }
	me->add("mana",-50);

        me->start_busy(2+random(2));
	destruct(seal);
	return 1;
}

int ji (string target)
{
  object seal = this_object ();
  object me = this_player();
  string name=seal->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+name+"？\n");

  victim=present(target,environment(me));
  seal->ji_ob(victim);
  return 1;
}

