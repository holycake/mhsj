#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(HIR "超影" NOR, ({ "chao ying", "ma"}));
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "马名超影，逐日而行。\n"+
		"玩家可以骑上(ride)它去指定的地方。\n");
	set("ridable", 1);
	set("int", 30);
	set("qi", 300);
	set("max_qi", 300);
	set("jing", 100);
	set("max_jing", 100);
	set("shen_type", 0);
	set("level",10);
	set("attitude", "peaceful");
       
	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	set("verbs", ({ "bite","hoof" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();

	set("chat_chance", 3);
        set("chat_msg", ({
                HIY"超影"NOR"抬头看了看你，继续埋下头吃它的夜草。\n",
                RED"超影"NOR"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
                MAG"超影"NOR"的长尾巴很不老实地不停地甩来甩去。\n",
        }) );
	seteuid(getuid());
}
