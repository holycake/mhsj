//snake.c

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(RED"赤冠巨蟒"NOR, ({ "ju mang", "snake" }) );
	set("race", "野兽");
	set("age", 20);
	set("long", "一只庞然大物，它眼中喷火，朱冠厉齿，好象要一口把你吞下。\n");
	set("attitude", "aggressive");
        set("qi", 5000);
	set("max_qi", 5000);
	set("jing", 500);
	set("max_jing", 500);
	set("str", 86);
	set("cor", 80);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );

	set("combat_exp", 1000000);

	//set("chat_chance",65);
	
	set_temp("apply/attack", 85);
	set_temp("apply/damage", 80);
	set_temp("apply/armor", 88);
	set_temp("apply/defence",80);

	setup();
}

int hit_ob(object me, object ob, int damage)
{
	if( random(damage) > (int)ob->query_temp("apply/armor")
	&&	(int)ob->query_condition("snake_poison") < 10 ) {
		ob->apply_condition("snake_poison", 40);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻木！\n" NOR );
	}
}
