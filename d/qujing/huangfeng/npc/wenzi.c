// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit NPC;

string *names = ({
  "[31m花脚蚊子[m",
  "大头蚊子",
  "紫头蚊子",
  "红头蚊子",
  "花边蚊子",
  "花肚蚊子",
});

void create()
{
  int i = random(sizeof(names));
  set_name(names[i], ({ "wen zi","wenzi" }) );
   set("race", "野兽");
   set("age", 3);
   set("long", "一只很小巧的花脚蚊子。\n");

   set("str", 32);
   set("max_kee",200);
   set("kee",200);
   set("max_sen",200);
   set("sen",200);
   set("limbs", ({ "头部", "身体", "腿", "翅膀", "嘴巴" }) );
   set("verbs", ({ "bite", "claw" }) );
   set("chat_chance",80);
   set("chat_msg",({
        "蚊子嗡嗡嗡的飞来飞去。\n",
        }));
   set_temp("apply/attack", 10);
   set_temp("apply/armor", 3);
   setup();
}
