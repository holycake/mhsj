// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit "/d/dntg/hell/wang.c";
inherit F_MASTER;

void create()
{
       set_name("轮转王", ({"lunzhuan wang", "wang"}));
       set("title", WHT"阴间十王之"NOR);
       set("gender", "男性");
       set("age", 70);
	set("class", "youling");
       set("attitude", "peaceful");
       set("shen_type", 1);
       set("per", 30);
        set("int", 30+random(5));
       set("max_kee", 2000);
       set("max_gin", 2000);
       set("max_sen", 2000);
       set("force", 6000);
       set("max_force", 3000);
       set("force_factor", 100);
       set("max_mana", 3000);
       set("mana", 6000);
       set("mana_factor", 100);
       set("combat_exp", 1660000);
  set("daoxing", 1500000);

	set_skill("spells", 200);
	set_skill("gouhunshu", 200);
       set_skill("unarmed", 239);
       set_skill("dodge", 239);
       set_skill("parry", 230);
	set_skill("force", 200);
	set_skill("tonsillit", 200);
	map_skill("spells", "gouhunshu");
	map_skill("force", "tonsillit");
	create_family("阎罗地府", 1, "你好");
setup();

        carry_object("/d/obj/cloth/mangpao")->wear();
//        carry_object("/d/lingtai/obj/shoe")->wear();
//        carry_object("/d/lingtai/obj/putibang")->wield();
}


