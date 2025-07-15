//Cracked by Roath
//mabu.c 抹布

inherit ITEM;

void create()
{
        set_name( "抹布", ({ "ma bu"}));
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
		set("unit", "块");
        set("long", 
		"这是一块抹布,本来好像是蓝色的，不过现在已经洗得发白了。\n");
		set("value",0);
	}
	setup();
}

