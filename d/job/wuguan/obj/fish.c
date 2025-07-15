//Cracked by Roath
//fish.c 鱼

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(CYN "鲤鱼"NOR, ({ "li yu","yu","fish"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
                set("long", 
"这是一条青色的鲤鱼,不过看起来没有多少肉，如果做菜也\n
不知道够不够，做汤看起来还可以。\n");
		set("value", 0);
	}
	setup();
}

