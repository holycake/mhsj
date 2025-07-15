#include <ansi.h>
#include <weapon.h>
inherit ITEM;


int reloading(object me);
int halt_reloading(object me);

void create()
{
        set_name(HIW"单眼铳"NOR, ({ "dan chong", "dan", "chong", "gun" }));
        set_weight(2000);
        if (clonep())
                set_default_object(__FILE__);
        else
        {
                set("unit", "把");
                set("long", "此铳甚为轻便，然只有一发,临敌不及装药。\n你可以用它来射(shot)些什么。\n");
				set("value", 100);
                set("power", 4000);   // 攻击威力
                set("accuracy", 80);   // 准确度，百分百为上限
        }
        setup();
}

void init()
{
        if (this_player() == environment())
        add_action("do_shot", "shot");
        add_action("do_reload", "reload");
        add_action("do_reload", "r");
}

int do_shot(string arg)
{
        string target;
        object me, victim;
        object ob,enemy;
        object env, *inv, *obs;
        int amount=0;
        int ap, damage;
        int i, count;
        string msg;

        me = this_player();
        if (me->query_temp("handing") != this_object())
                return notify_fail("你得先把" + name() + "拿(hand)在手中才行。\n");

        env = environment(me);
        if (! env || env->query("no_fight"))
                return notify_fail("这里不能战斗，也不准鸣枪。\n");

        if (me->is_busy())
                return notify_fail("你现在手忙脚乱着呢。\n");

        if (me->query("jing") < 80)
                return notify_fail("你现在神志不清，无法使用" + name() + "瞄准对手。\n");

		inv = all_inventory(me);
		for (count = 0, i = 0; i < sizeof(inv); i++) {
			if( inv[i]->is_bullet() )
			{
				if( (amount = inv[i]->query_amount() ) < 1 )
				{
					return notify_fail("弹药数量不足。\n");
				}
				ob = inv[i];
			}
			count++;
		}

		if( !amount )
			return notify_fail("你身上没有弹药可以发射。\n");
/*
        if ( ! arg && ! me->is_fighting())
                return notify_fail("你要攻击谁？shot [对象]\n");
*/
        if ((int)me->query_temp("shot_times") < 1)
                return notify_fail("还未装填子药，无法射击。\n");

        if ( arg && sscanf(arg, "%s", target) > 1)
				return notify_fail("你要攻击谁？shot [对象]\n");

		if ( ! arg )
		{
	        obs = filter_array(all_inventory(env),
	                           (: $1->is_character() &&
	                              $1->is_killing($(me)->query("id")) &&
	                              $1->query_competitor() != $(me) :));
	        if (sizeof(obs))
	        {
	                foreach (enemy in obs)
	                {
	                	target=enemy->query("id");
	                }
	        }
	    }

        if (! target || ! objectp(victim = present(target, env)))
        {
        	me->add_temp("shot_times", -1);
        	ob->add_amount(-1);
              return notify_fail("你举起火铳对空放了一枪。\n");
        }

        if (! victim->is_character() || victim->query("not_living"))
                return notify_fail("看清楚了，那不是活人！\n");
/*
        if (! me->is_fighting(victim))
                return notify_fail("你只能射击战斗中的对手。\n");
*/

        switch (random(3))
        {
        case 0:
                msg = "$N给" + name() + "填上火药，将一" + ob->query("base_unit") +
                      ob->name() + "塞入铳口，瞄准了$n！\n";
                break;

        case 1:
                msg = "$N忽的一下射出一" + ob->query("base_unit") +
                      ob->name() + "，直奔$n而去！\n";
                break;

        default:
                msg = "只听“嗖”的一声破空声，$N对准$n射出一" + ob->query("base_unit") +
                      ob->name() + "！\n";
                break;
        }
        ap=random(100);
        if (ap > query("accuracy")*ob->query("wound_percent"))
        {
                switch (random(3))
                {
                case 0:
                        msg += "却见$n轻轻一闪，将$N的" + ob->name() + "避了开去。\n";
                        break;
                case 1:
                        msg += "只见$n不慌不忙，身子一扭，躲开了$N这一招。\n";
                        break;
                default:
                        msg += "$n身子往后一仰，让$N的" + ob->name() + "落了个空。\n";
                        break;
                }
                message_vision(msg, me, victim);
        } else
        {
                damage = query("power");
                msg += HIR "只见$n一个闪避不及，被火铳一弹正中，鲜血四溅，伤口焦黑！\n" NOR;
                victim->receive_damage("kee", damage); // 气血伤害
                victim->receive_damage("sen", damage); // 精神伤害
                message_vision(msg, me, victim);
        }
        me->add_temp("shot_times", -1);
        ob->add_amount(-1);
//        me->start_busy(2);
//        me->receive_damage("jing", 10);

        victim->kill_ob(me);
        return 1;
}

int do_reload()
{
	object me;
	me = this_player();

	message_vision("$N开始给" + name() + "装填子药。。。\n", me);
	me->set_temp("last_shot", time());
	me->start_busy((: reloading :), (: halt_reloading :));
	return 1;
}

int reloading(object me)
{
        object ob;
        int i, count;
        object *inv;
        int amount=0;
        int b;

		inv = all_inventory(me);
		for (count = 0, i = 0; i < sizeof(inv); i++) {
			if( inv[i]->is_bullet() )
			{
				if( (amount = inv[i]->query_amount() ) < 1 )
				{
					return notify_fail("弹药数量不足。\n");
				}
				ob = inv[i];
			}
			count++;
		}

		if( !amount )
			return notify_fail("你身上没有弹药可以发射。\n");

	    switch (random(5))
        {
        case 0:
                message_vision("$N正在往" + name() + "里装填" + ob->name() + "。。。\n", me);
        }

        if (time() - (int)me->query_temp("last_shot") >= 5)
        {
                me->set_temp("shot_times", 1);
	            message_vision("$N的" + name() + "装填" + ob->name() + "完毕！！！\n", me);

                b = (int)me->query("level")*random(1000);
                me->improve_exp(me,b);
                me->improve_potential(b);
                return 0;
        }
        return 1;
}
int halt_reloading(object me)
{
        message_vision("$N停止给火铳装填子药。\n", me);
        return 1;
}