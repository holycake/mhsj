//change.c
#include <ansi.h>
inherit NPC;
void create()
{
           set_name("织女", ({"zhi nu", "zhinu", "xian"}));
       set("long",
"西王母的外甥女。因为私自下凡与牛郎相爱，而被罚银河永隔，\n只有每年的七月初七才能鹊桥相会。\n");
       set("gender", "女性");
       set("age", 20);
       set("class", "xian");
        set("title", HIM"望夫心切"NOR);
       set("attitude", "friendly");
       set("rank_info/respect", "仙姑");
       set("per", 30);
	set("int", 30);
         set("max_kee", 1500);
         set("max_gin", 1500);
         set("max_sen", 1500);
         set("force", 1200);
         set("max_force", 1200);
       set("force_factor", 50);
         set("max_mana", 1200);
         set("mana", 1200);
         set("mana_factor", 80);
         set("combat_exp", 800000);
        //   carry_object("/d/moon/obj/luoyi")->wear();
         //    carry_object("/d/obj/flower/rose")->wear();
 setup();   
}

void announce_success (object who)
{
  int i;

  if (who->query("combat_exp") < 2000000)
    return;
  if (who->query("obstacle/niulang") == "done")
    return;
  if (!who->query_temp("daqiao")||!who->query_temp("ask_niulang"))
    return;
  i = random(24000);
  who->set("obstacle/niulang","done");
  who->add("daoxing",i);
  who->add("combat_exp",50000);
  who->add("potential",50000);
//  command("chat "+who->query("name")+"大智大勇，助我与夫君团圆！");
  message("shout", HIC"〖"HIM"鹊桥相会"HIC"〗织女(Zhi nu)："+ HIW+who->query("name")+HIC"大智大勇，助我与夫君团圆！\n"NOR,users());
tell_object (who,"你赢得了"+COMBAT_D->chinese_daoxing(i)+"的道行！\n");
  who->save();
}

