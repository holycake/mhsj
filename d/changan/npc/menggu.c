//By waiwai@mszj 2000/10/26

inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIR"蒙古大夫"NOR, ({ "menggu doctor","doctor"}));
	set("title", HIB"民间"NOR);
	set("nickname", BLINK+HIG"全靠一把刀"NOR);
	set("shen_type", 1);

	set("str", 50);
	set("gender", "男性");
	set("age", 35);
	set("long",HIC
		"这个大夫长安城里唯一的一位做变性手术的人，掌管玩家的男女性别大权。\n"NOR);
	set("combat_exp", 9500000);
	set("attitude", "friendly");
	
	setup();
	
}
