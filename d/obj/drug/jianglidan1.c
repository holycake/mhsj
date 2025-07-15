// jianglidan1.c 奖励丹

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                set("no_drop","这么宝贵的奖励丹，哪能乱扔! \n");
       
        }
                                              
        add_action("do_eat", "eat");
}

void create()
{
        set_name(HIG "奖励丹" NOR, ({"jiangli dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "粒");
                set("long", "一粒奖励丹，吃了能功力倍增,是难得的灵丹妙药!\n");
                set("value", 0);
        }

        set("is_monitored", 1);
        setup();
}

                       
int do_eat(string arg)
{
        object victim = this_player();

           if( (int)victim->query("cat")> 2 )
        {
            message_vision(HIG "\n$N吃下一粒奖励丹,忽然感到一阵倒胃，就差没把肠子也给吐出来!\n\n" NOR, victim);
              destruct(this_object());                
		return 1;
	}


        if (!id(arg))
                return notify_fail("你要吃什么？\n");

        victim->set("cat", 3 );
        victim->add("combat_exp", random(5000)+5000+(int)victim->query("combat_exp") / 40);
        if( (int)victim->query("potential") > (int)victim->query("learned_points"))
		victim->add("potential",
                        (int)victim->query("potential") - (int)victim->query("learned_points")+5000+random(5000) );
	victim->skill_death_recover();

   victim->add("daoxing",random(6000)+10000+victim->query("death/dx_loss"));
        victim->save();

	if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );

       message_vision(HIG "\n$N吃下一粒奖励丹,渐渐地一股内息流遍全身,顿时精神大震,倍感舒适!\n\n" NOR, victim);

        destruct(this_object());
        return 1;
}

