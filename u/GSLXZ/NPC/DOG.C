// dog.c
#include <ansi.h>

inherit NPC;

void create()
{
	set_name(HIW"旺财"NOR, ({ "dog" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", HIG"西瓜太郎"HIR"的爱犬，"HIY"旺财。\n"NOR);
	
	set("str", 24);
	set("cor", 26);

	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );
	
	set_temp("apply/attack", 10);
	set_temp("armor", 3);

	setup();
}
