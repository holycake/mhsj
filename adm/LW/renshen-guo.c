
// renshen-guo.c 人参果
// suppose to be able to be given and got,
// please let me know before changing...weiqi980417

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();
void init()
{
        if (!wizardp(this_player())) {
                set("no_get", "嘿嘿，做梦吧! \n");
                        set("no_give","这么珍贵的药，哪能随便给人？\n");
                set("no_drop","这么宝贵的人参果，哪能乱扔! \n");
                   set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
}
          add_action("do_eat", "eat");
}

void create()
{
	set_name(HIW "人参果" NOR, ({"renshen guo", "renshenguo", "guo"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "枚");
		set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
		set("value", 500000);
		set("drug_type", "补品");
	}
  
	set("is_monitored",1);
	setup();
}

int do_eat(string arg)
{
	int howmany;

	object me = this_player();
  
	if (!id(arg)) return notify_fail("你要吃什么？\n");

	howmany = (int)me->query("rsg_eaten");
  
	me->set("food", (int)me->max_food_capacity());

		if( howmany <= 100 ) me->add_maximum_force(20);
		if( howmany <= 100 ) me->add_maximum_mana(20);

	me->set("rsg_eaten", howmany+1);

	message_vision(HIW "$N把人参果往嘴里一塞，忍不住大叫一声：人参果啊人参果，不愧是人参果！ \n说罢兴奋得都快晕了过去。\n" NOR, me);  

	me->set("obstacle/wuzhuang","done");

        //for live forever...
        if( me->query("rsg_eaten") >= 36 )
        {
                me->announce_live_forever( me->query("name")+"坚持不懈地吃人参果，终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
        }

	me->unconcious();
	destruct(this_object());

	return 1;
}

