//Cracked by Roath
// tong.c 水桶
// by yfengf

inherit ITEM;

void create()
{
        set_name( "水桶", ({"shui tong","tong"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "个");
                set("long", 
"这是一个打水的桶。\n");
		set("value", 5000);
		set("material", "wood");
	}
	setup();
}

