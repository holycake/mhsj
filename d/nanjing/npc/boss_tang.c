// tang.c 唐老板 
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("唐槐", ({ "tang huai", "tang", "huai", "boss" }));
	set("title", "当铺老板");
	set("shen_type", 0);
	set("gender", "男性");
	set_max_encumbrance(100000000);
	set("age", 35);
        set("str", 100);
	set("long",
		"据说唐槐是四川唐家的后代。\n");
	set("no_get_from", 1);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_temp("apply/attack", 30);
	set_temp("apply/attack", 30);
	set_temp("apply/damage", 15);
	set("attitude", "friendly");
	
	setup();
	carry_object("/d/nanjing/obj/mao_min"+random(11))->wear();
	carry_object("/d/nanjing/obj/cloth_nv"+random(7))->wear();
	//carry_object("/d/nanjing/obj/skirt_nv"+random(24))->wear();
	carry_object("/d/nanjing/obj/shoes"+random(8))->wear();

}
