// six-book.c
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name( HIC"六脉神剑谱"NOR,({ "sixfinger book","book"}));
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "本");
                set("long","这是一幅图。上面都是纵横交叉的直线、圆圈和弧形。\n");
		set("value", 500);
		set("material", "paper");
		set("skill", ([
                        "name":         "six-finger"  ,//name of the skill
                        "exp_required": 100000,        //minimum combat experience required
			"gin_cost":    20+random(20),// jing cost every time study this
			"difficulty":	20,           // the base int to learn this skill
			"min_skill":	0,            // the minimum level you can learn
			"max_skill":	99            // the maximum level you can learn
		]) );
	}
}
