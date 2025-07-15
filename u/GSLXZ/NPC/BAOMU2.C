inherit NPC;

#include <ansi.h>
int give_dou ();

int create()
{
  set_name(HIM"忽悠"NOR, ({"come","come_npc", "mu"}));
  set("long", "一位貌美如花的小姑娘。\n");

  set("gender", "女性");
  set("attitude", "peaceful");
  set("class", "bonze");
  set("age", 15);
  set("str", 20);
  set("int", 30);
  set("per", 40);
  set("con", 20);
  set("max_kee", 400);
  set("max_sen", 400);
  set("max_force", 300);
  set("force", 300);
  set("force_factor", 10);
  set("max_mana", 400);
  set("mana", 400);
  set("mana_factor", 10);
  set("combat_exp", 50000);
  set("daoxing", 80000);


  set("chat_chance", 5);
  set("chat_msg", ({
    "忽悠叹道：西瓜少爷，需要我为你捶背吗?\n",
    "忽悠说道：西瓜少爷，我做的可可豆出锅了，你要吃点吗?\n",
    "忽悠叹道：西瓜少爷，今天我做炉包，你吃吗?\n",
  }));
  set("inquiry", ([
    "可可豆" : (: give_dou :),
    "dou" : (: give_dou :),
  ]) );

  set_skill("force", 50);
  set_skill("unarmed", 50);
  set_skill("dodge", 79);
  set_skill("parry", 79);
  set_skill("staff", 50);
  set_skill("lotusforce", 50);
  set_skill("lunhui-zhang", 79);
  set_skill("jienan-zhi", 50);
  set_skill("lotusmove", 79);
  map_skill("dodge", "lotusmove");
  map_skill("unarmed", "jienan-zhi");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "lotusforce");
  setup();
  add_money("silver", 5);
  carry_object("/u/gslxz/obj/skirt")->wear();
  carry_object("/u/gslxz/obj/dou");
  set("dous", 3);
  setup();
}

int give_dou ()
{
  object who = this_player();
  object dou;

  if (query("dous") <= 0)
  {
    command ("say 不给了，不给了，你们把豆吃光了，我怎么跟西瓜少爷交待呀！");
    return 1;
  }
  
  dou = new ("/u/gslxz/obj/dou");
  add("dous",-1);
  message_vision (HIM"忽悠"NOR"给$N一颗$n。\n",who,dou);
  dou->move(who);
  return 1; 
}

