// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("昴宿星官", ({"maoxiu xingguan", "xingguan", "guan"}));
  set("gender", "男性");
  set("age", 100);
  set("attitude", "friendly");
  set("combat_exp", 1250000);
  set("daoxing", 1500000);

  set("per", 25);
  set_skill("dodge", 120);
  set_skill("force", 120);
  set_skill("parry", 120);
  set_skill("spells",160);
  set_skill("dao", 120);
  set_skill("dragonforce", 120);
  set_skill("dragonstep", 120);
  set_skill("dragonfight", 120);
  map_skill("unarmed", "dragonfight");
  map_skill("dodge", "dragonstep");
  map_skill("spells", "dao");
  set("max_sen",1600);
  set("max_gee",1600);
  set("max_gin",1600);
  set("force",1800);
  set("max_force",1800);
  set("max_mana",1800);
  set("force_factor",125);
  setup();

  carry_object("/d/obj/cloth/changpao")->wear();

}

void announce_success (object who)
{//disabled announce and reward...
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/dudi") == "done")
    return;
  if (! who->query_temp("obstacle/dudi_killed"))
    return;
  i = random(800);
  who->add("obstacle/number",1);
  who->set("obstacle/dudi","done");
  who->add("daoxing",i+3000);
  command("chat "+who->query("name")+"毒敌山显圣名，琵琶洞除蝎怪！");
message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第二十关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(3)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}

