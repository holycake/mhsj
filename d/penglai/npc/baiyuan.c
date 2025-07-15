// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIW"白猿"NOR, ({ "bai yuan", "yuan" }) );
        set("race", "野兽");
        set("age", 80);
        set("long", "一只浑身长着寸许长白毛的老猿。\n");

        set("str", 30);
        set("dex", 30);
	set("int", 30);
	set("con", 30);
	set("cor", 50);
	set("spi", 50);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 2999000);
  set("daoxing", 2200000);

	set_skill("unarmed", 350);
	set_skill("changquan", 350);
	set_skill("sword", 370);
	set_skill("xiaofeng-sword", 370);
	set_skill("parry", 370);
	set_skill("dodge", 350);
	set_skill("moshenbu", 350);
	set_skill("force", 350);
	set_skill("spells", 350);
	map_skill("dodge", "moshenbu");
	map_skill("parry", "xiaofeng-sword");
	map_skill("sword", "xiaofeng-sword");
	map_skill("unarmed", "changquan");

	set("max_kee", 1600);
	set("max_sen", 1600);
	set("mana", 4000);
	set("max_mana", 2000);
	set("mana_factor", 100);
	set("force", 4000);
	set("max_force", 2000);
	set("force_factor", 120);

        set_temp("apply/attack", 20);
        set_temp("apply/armor", 50);

        setup();
	carry_object("/d/obj/weapon/sword/changjian")->wield();
}

