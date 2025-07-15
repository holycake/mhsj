// medicine.c

inherit ITEM;

void create()
{
	set_name("回天散",({"huitiansan"}));
        set_weight(60);
        if( clonep() )
                set_default_object(__FILE__);
	else {
	    set("long",
     	        "一丸被视为少林之宝的回天散。\n");
	    set("unit","丸");
	    set("value", 20000);
	}
}

void init()
{
  if(this_player()==environment())
	add_action("apply_medicine","yong");
}

int apply_medicine()
{
	int value = 40;
	int diff;

	if(this_player()->is_fighting())
	    return notify_fail("战斗中不能用药！！\n");
	diff = this_player()->query("max_kee")-this_player()->query("eff_kee");
	if(!(diff))    return notify_fail("你没有受伤！\n");
	if(value > diff) value = diff;
	    
	message_vision("$N用回天散疗伤．\n",this_player());
	this_player()->add("eff_kee",value);
	destruct(this_object());
	return 1;
}


