// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
   set_name(HIC"素素"NOR, ({ "su su", "susu"}));
   set("gender", "女性" );
   set("age", 15);
   set("per",39);
   set("long",
     "一位绝色美女。\n");

   set("combat_exp", 600+random(400));
   set("attitude", "friendly");
   set_skill("dodge", 10);
   set_skill("unarmed", 10);
   setup();
   carry_object("/obj/cloth")->wear();
   add_money("silver", 3+random(20));
}

