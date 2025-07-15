// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("宫女", ({"girl", "gongnu"}));
  set("gender", "女性");
  set("age", 15);
  set("combat_exp", 2500);
  set_skill("unarmed", 5);
  set_skill("dodge", 5);
  set_skill("parry", 5);
  set("force", 10);
  set("max_force", 10);

  setup();
}

void init()
{
  ::init();
}

