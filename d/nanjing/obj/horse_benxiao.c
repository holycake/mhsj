#include <ansi.h>

inherit NPC;
inherit F_UNIQUE;

void create()
{
	set_name(MAG"奔霄" NOR, ({ "ben xiao", "ma"}));
	set("race", "野兽");
	set("gender", "雄性");
	set("age", 2+random(3));
	set("long", "马名奔霄，夜行万里。\n"+
		"玩家可以骑上(ride)它去指定的地方。\n");
	set("ridable", 1);
	set("int", 30);
	set("kee", 300);
	set("max_kee", 300);
	set("sen", 100);
	set("max_sen", 100);
	set("shen_type", 0);
	set("attitude", "peaceful");
       
	set("limbs", ({ "头部", "腹部", "尾巴","后腿","前腿" }) );
	set("verbs", ({ "bite","hoof" }) );
	set_temp("apply/attack", 50);
	set_temp("apply/armor", 15);
	set_temp("apply/damage", 25);

	setup();

	set("chat_chance", 3);
        set("chat_msg", ({
                HIY"奔霄"NOR"抬头看了看你，继续埋下头吃它的夜草。\n",
                RED"奔霄"NOR"扯了扯缰绳，然后不耐地在地上刨着蹄子。\n",
                MAG"奔霄"NOR"的长尾巴很不老实地不停地甩来甩去。\n",
        }) );
	seteuid(getuid());
}
