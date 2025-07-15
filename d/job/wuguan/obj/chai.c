//Cracked by Roath
//chai.c 柴

inherit ITEM;

void create()
{
        set_name( "柴", ({"chai"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "块");
                set("long", 
"这是一块劈开的柴火，看上去劈柴的人水平并不高，柴火批的毛毛糙糙。\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}

