// medicine.c

inherit ITEM;

void create()
{
	set_name("小还丹",({"xiaodan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一丸被视为少林之宝的小还丹，只有米粒大小。\n");
	    set("unit","丸");
	    set("value", 20000);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","yong");
}

int apply_medicine(string arg)
{
	object victim;
	if(!arg || !objectp(victim=present(arg,environment(this_player()))))
	victim = this_player();
	if(this_player()->is_fighting() || environment(victim)->query("no_magic"))
	    return notify_fail("现在不能用药！！\n");
        if(victim != this_player() && random((int)victim->query("combat_exp")) >
        (int)   this_player()->query("combat_exp"))
	{
		message_vision("$N对$n喝道：大胆！竟敢对我下毒！！\n",victim,this_player());
		victim->kill_ob(this_player());
		this_player()->kill_ob(victim);
		this_player()->start_busy(2);
	}
	tell_object(this_player(),"你用指甲将小还丹碾成粉末，轻轻地弹在"+
	victim->name()+"身上。\n");
		victim->apply_condition("unknown",random(20)+5);
	destruct(this_object());
	return 1;
}


