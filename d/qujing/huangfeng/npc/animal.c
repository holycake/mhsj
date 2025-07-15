// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

string *names = ({
  "小松鼠",
  "小野兔",
  "小野猫",
  "小刺猬",
});

string *ids = ({
  "xiao songsu",
  "xiao yetu",
  "xiao yemao",
  "xiao ciwei",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ids[i]}));
  set("race", "野兽");
  set("age", 6);
  set("str", 30);
  set("cor", 26); 
  set("combat_exp",50);
  set_skill("dodge",20);
  set_skill("unarmed",10);
  set("limbs", ({ "头部", "身体", "前爪", "后脚", "尾巴" }) );
  set("verbs", ({ "bite", "claw" }) );
  setup();
}
