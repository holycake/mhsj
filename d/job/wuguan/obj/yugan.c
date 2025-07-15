//Cracked by Roath
//yugan.c 鱼竿

inherit ITEM;

void create()
{
        set_name( "鱼竿", ({ "yu gan" , "gan"}));
	set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("long", "这是一根普通的鱼竿,做工不甚精细，也不知道用这玩艺能不能钓上鱼。\n");
		set("value", 0);
		set("material", "wood");
	}
	setup();
}

