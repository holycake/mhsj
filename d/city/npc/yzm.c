// by mhsj@gslxz /2001/7/27
// yanzhima.c
#include <ansi.h>

inherit NPC;

void create()
{
          set_name(HIW"雪蹄"HIM"胭脂马"NOR, ({"yanzhi ma", "ma", "horse"}));
	set("race", "野兽");
	set("age", 10);
            set("combat_exp", 700000);
            set("daoxing", 3370000);
            set("max_force", 3000);
            set("force", 3000);
            set("max_mana", 3000);
            set("mana", 3000);
            set("max_kee", 2000);
            set("kee", 2000);
            set("max_sen", 2000);
            set("sen", 2000);
          set("per", 30);
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite"}));

              set("ride/msg", WHT"骑"NOR);
          set("ride/dodge", 120);
	set_temp("apply/attack", 10);
	set_temp("apply/armor", 20);

	setup();
}


