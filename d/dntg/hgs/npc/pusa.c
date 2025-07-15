// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

int do_drop(object, object);

void create()
{
   set_name("观音菩萨", ({ "guanyin pusa", "guanyin", "pusa" }));
   set("title", "救苦救难大慈大悲");
   set("long", @LONG
理圆四德，智满金身。眉如小月，眼似双星。兰心欣紫竹，
蕙性爱得藤。她就是落伽山上慈悲主，潮音洞里活观音。
LONG);
   set("gender", "女性");
   set("age", 35);
   set("attitude", "peaceful");
   set("rank_info/self", "贫僧");
   set("rank_info/respect", "菩萨娘娘");
   set("class", "bonze");
   set("str",24);
   set("per",100);//means no rong-mao description.
   set("max_kee", 5000);
   set("max_gin", 5000);
   set("max_sen", 5000);
   set("force", 4000);
   set("max_force", 2000);
   set("force_factor", 145);
   set("max_mana", 3000);
   set("mana", 6000);
   set("mana_factor", 150);
   set("combat_exp", 2000000);
   create_family("南海普陀山", 1, "菩萨");
   setup();
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 10000)
    return;
  if (who->query("obstacle/zj") == "done")
    return;
  if (who->query_temp("obstacle/liuer_killed"))
    return;
  i = random(700);
  who->add("obstacle/number",1);
  who->set("obstacle/zj","done");
  who->add("daoxing",i+4000);
  command("chat "+who->query("name")+"花果山打败六耳猕猴！");
  message("channel:chat",HIY"【过关斩将】观音菩萨(guanyin pusa)："+who->query("name")+"闯过西行取经[1;37m第十八关！\n"NOR,users());
  tell_object (who,"你赢得了"+chinese_number(4)+"年"+
               chinese_number(i/4)+"天"+
               chinese_number((i-(i/4)*4)*3)+"时辰的道行！\n");
  who->save();
}
