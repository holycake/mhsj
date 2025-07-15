// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
       set_name("卞城王", ({"biancheng wang", "wang"}));
       set("title", WHT"阴间十王之"NOR);
       set("gender", "男性");
	set("class", "youling");
       set("age", 50);
       set("attitude", "friendly");
       set("per", 30);
        set("int", 30);
       set("max_kee", 2000);
       set("max_gin", 2000);
       set("max_sen", 2000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 5000);
       set("mana_factor", 100);
	set("combat_exp", 1600000);
  set("daoxing", 1500000);

	set_skill("spells", 219);
	set_skill("gouhunshu", 219);
       	set_skill("unarmed", 219);
       	set_skill("dodge", 219);
	set_skill("parry", 219);
	set_skill("force", 200);
	set_skill("tonsillit", 200);
	map_skill("force", "tonsillit");
create_family("阎罗地府", 1, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
}


