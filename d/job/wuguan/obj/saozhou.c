//Cracked by Roath
//saozhou.c 扫帚

inherit ITEM;

void create()
{
        set_name( "扫帚", ({ "sao zhou"}));
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long", "这是一把扫地用的大扫帚，秃秃的扫帚头，看起来这把扫帚马上就要被丢弃了。\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}

