//Cracked by Roath
// quanpu.c

inherit ITEM;

void create()
{
	set_name( "拳谱总诀",({"quanpu zongjue", "shu","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
		set("long","这是一本拳谱总诀。\n");
		set("value", 500);
		set("treasure",1);
		set("material", "paper");
		set("skill", ([
			"name": "cuff",
			"exp_required": 10000 , //minimum combat experience required
			"jing_cost": 20+random(20),// jing cost every time study this
			"difficulty":	20,	// the base int to learn this skill
			"max_skill":	40,	// the maximum level you can learn
			"min_skill":	10	// the minimum level you can learn
		]) );
	}
}
