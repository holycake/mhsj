inherit NPC;
#include <ansi.h>
int give_smoke ();
int create()
{
  set_name(HIC"青云"NOR, ({"gyljk","gyljk_npc", "mu"}));
  set("long", "长的非常帅气的小哥。\n");
  set("gender", "男性");
  set("attitude", "peaceful");
  set("class", "bonze");
  set("age", 15);
  set("str", 20);
  set("int", 30);
  set("per", 40);
  set("con", 20);
  set("max_kee", 4000);
  set("max_sen", 4000);
  set("max_force", 3000);
  set("force", 3000);
  set("force_factor", 500);
  set("max_mana", 4000);
  set("mana", 4000);
  set("mana_factor", 500);
  set("combat_exp", 5000000);
  set("daoxing", 8000000);
  set("chat_chance", 5);
  set("chat_msg", ({
    "青云问道：西瓜少爷，需要我为你做点什么吗？\n",
  "青云叹道：西瓜少爷什么时候才能给我介绍一个漂亮妹妹呀？\n",
//  (: random_move :)
  }));
  set("inquiry", ([
    "香烟" : (: give_smoke :),
    "smoke" : (: give_smoke :),
  ]) );
  set_skill("force", 1000);
  set_skill("unarmed", 1000);
  set_skill("dodge", 1000);
  set_skill("parry", 1000);
  set_skill("staff", 1000);
  set_skill("lotusforce", 1000);
  set_skill("lunhui-zhang", 1000);
  set_skill("jienan-zhi", 1000);
  set_skill("lotusmove", 1000);
  map_skill("dodge", "lotusmove");
  map_skill("unarmed", "jienan-zhi");
  map_skill("staff", "lunhui-zhang");
  map_skill("parry", "lunhui-zhang");
  map_skill("force", "lotusforce");
  setup();
  add_money("silver", 5);
  carry_object("/u/gslxz/obj/majia")->wear();
  carry_object("/u/gslxz/obj/smoke");
  set("smokes", 30);
  setup();
}
int give_smoke ()
{
  object who = this_player();
  object smoke;
  if (query("smokes") <= 0)
  {
    command ("say 不给了，都给你们我怎么办？");
    return 1;
  }
  
  smoke = new ("/u/gslxz/obj/smoke");
  add("smokes",-1);
  message_vision ("青云给$N一根$n。\n",who,smoke);
  smoke->move(who);
  return 1; 
}
