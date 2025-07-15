// dizi.c

#include <ansi.h>
inherit NPC;

void create()
{
	int skill;

	set_name("武器搬运工", ({ "gongren" }) );
	set("gender", "男性" );
	set("age", 18+random(10));
	set("long", "你看到一位身材高大的汉子，正在辛苦地搬运武器。\n");

	set("combat_exp",4000);


	set_skill("dodge", 10);
	set_skill("unarmed", 10);

	setup();
	carry_object("/d/qujing/jindou/obj/jindan");
            carry_object("/d/obj/weapon/throwing/kongqueling");
            carry_object("/d/obj/weapon/throwing/kongqueling");
            carry_object("/d/obj/weapon/throwing/kongqueling");
            carry_object("/d/obj/weapon/throwing/kongqueling");
            carry_object("/d/obj/weapon/throwing/kongqueling");
}
