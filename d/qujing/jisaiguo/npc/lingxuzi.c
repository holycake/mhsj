// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
       	set_name("凌虚子", ({"lingxu zi", "zi"}));
       	set("gender", "男性");
       	set("age", 30);
        set("long", "一个身高臂长的道士，容貌还看的过去。
可仔细一瞧，颈中竟长着密密麻麻的长毛。\n");
       	set("attitude", "heroism");
	set("class", "yaomo");
	set("bellicosity", 800);
       	set("per", 18);
	set("looking", "相貌凶恶，满脸横肉。");
	set("str", 25);
       	set("combat_exp", 920000);
  set("daoxing", 520000);

        set_skill("unarmed", 175);
        set_skill("dodge", 175);
        set_skill("blade", 175);
        set_skill("parry", 175);
	set_skill("force", 175);
	set_skill("spells", 175);
	set_skill("moshenbu", 175);
	set_skill("cuixin-zhang", 175);
	map_skill("unarmed", "cuixin-zhang");
	map_skill("parry", "cuixin-zhang");
	map_skill("dodge", "moshenbu");
        set("force", 3000);
        set("max_force", 3000);
        set("force_factor", 120);
        set("max_kee", 2000);
        set("max_sen", 2000);
        set("max_mana", 3000);
        set("mana", 3000);
	set("mana_factor", 120);
	set("eff_dx", -50000);
	set("nkgain", 300);
	set_temp("apply/armor", 25);
	setup();
	carry_object("/d/obj/cloth/changpao")->wear();
	carry_object("/d/qujing/jisaiguo/obj/panzi");
}


