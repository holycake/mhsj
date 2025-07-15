// medicine.c
inherit ITEM;
void create()
{
	set_name("观音像",({"guan yin"}));
        set_weight(6000);
	set("no_get",1);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一尊观音像，据传跪拜（knee）以后，领悟武功会突飞猛进．\n");
	    set("unit","尊");
	    set("value", 20000);
	}
}

void init()
{
	add_action("apply_effect","knee");
}

int apply_effect()
{
	int value = 20;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("战斗中怎么能跪拜观音？\n");
		    
	message_vision("$N＂噗嗵＂一声，跪倒在观音像前，恭恭敬敬地磕了三个响头！\n",this_player());
	this_player()->receive_damage("kee",10);
	if(!random(500)) this_player()->add("int",-1);
	return 1;
}


