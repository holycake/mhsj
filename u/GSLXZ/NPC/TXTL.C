inherit NPC;

#include <ansi.h>
int give_book ();

int create()
{
  set_name(HIW"桃心太郎"NOR, ({"iiiii_npc","iiiii", "mu"}));
  set("long", "一位样貌出众的青岛小哥。\n");

  set("gender", "男性");
  set("attitude", "peaceful");
  set("title", HIG"西瓜太郎"HIR"的好伙伴");
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


//  set("chat_chance", 5);
  set("chat_msg", ({
    "忽悠叹道：西瓜少爷，需要我为你捶背吗?\n",
    "忽悠说道：西瓜少爷，我做的可可豆出锅了，你要吃点吗?\n",
    "忽悠叹道：西瓜少爷，今天我做炉包，你吃吗?\n",
  }));
  set("inquiry", ([
//    "花花公子" : (:  :),
//   "阁楼杂志" : (: give_book :),
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
  carry_object("/d/obj/cloth/sengyi")->wear();
  carry_object("/d/obj/cloth/sengxie")->wear();
  carry_object("/d/obj/books-nonskill/mxzj");
  set("books", 3);
  setup();
}

int give_book ()
{
  object who = this_player();
  object book;

  if (query("books") <= 0)
  {
    command ("shake");
    return 1;
  }
  
  book = new ("/d/obj/books-nonskill/mxzj");
  add("books",-1);
  message_vision ("桃心太郎给$N一本$n。\n",who,book);
  book->move(who);
  return 1; 
}

