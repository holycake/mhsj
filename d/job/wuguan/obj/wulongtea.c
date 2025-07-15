//Cracked by Roath
//wulongtea.c 乌龙茶
//by yfengf

#include <ansi.h>

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name(YEL"乌龙茶"NOR,({"wulong tea","wulong cha","tea", "cha"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", 
"这是一杯上好的洞顶乌龙，是每次管主款待客人用的。");
		set("unit", "杯");
        set("value", 1);
        set("drink_supply", 35);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	if( !this_object()->id(arg) ) 
		return 0;
	if( this_player()->is_busy() )
        	return notify_fail("你上一个动作还没有完成。\n");
    	if((int)this_player()->query("water")>= (int)this_player()->max_water_capacity() )
		return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
	if( this_player()->is_fighting() )
		return notify_fail("你先专心打架，打完了再喝茶也不迟。\n");

	set("value", 0); //茶喝过，就不值钱了。
    	this_player()->add("water", (int)query("drink_supply"));
	this_player()->start_busy(1);
	add("remaining", -1);
	if ( query("remaining") )
	{
		message_vision("$N端起杯"+YEL"乌龙茶"NOR+"，有滋有味地品了几口。\n"+
      		"一股香气直入心脾，$N觉得精神好多了。\n", this_player());
	}
	else 
	{ 
		message_vision("$N端起雕花小杯，把剩下的"+YEL"乌龙茶"NOR+"一饮而尽。\n"+
      		"一股香气直入心脾，$N觉得精神好多了。\n", this_player());
		destruct(this_object());
	}
	return 1;
}
