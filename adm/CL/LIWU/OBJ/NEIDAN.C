

#include <ansi.h>


inherit ITEM;

 void create()
{
        set_name(HIG "蛟龙内丹" NOR, ({"nei dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "枚");
                set("long", "一枚能增十年功力的蛟龙内丹。\n");
                set("value", 20000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," 嘿嘿，做梦吧! \n");
        set("no_drop","这么宝贵的东东，哪能乱扔! \n");
	   set("no_give","你太慷慨了吧！\n");
       }
        add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
        int force_limit, neili_limit,improve;

	object me = this_player();
        if( !living(me) )
		return notify_fail("你想当机吗？\n");


	force_limit = me->query_skill("force")*10;
	neili_limit = me->query("max_neili");
	
	if (!id(arg))
	return notify_fail("你要吃什么？\n");

        if ( neili_limit <= force_limit  )
	{  improve=20+random(me->query_skill("force")/2);
                                  
           me->add("max_neili",improve);
		message_vision(HIY "$N吃下一枚蛟龙内丹，顿然间丹田之中真气澎湃...\n" NOR, this_player());
         
		
	}
        else 
        message_vision(HIY "$N吃下一枚蛟龙内丹，不过好象没什么感觉...\n" NOR, this_player());
		   
	
	destruct(this_object());
	return 1;

}


