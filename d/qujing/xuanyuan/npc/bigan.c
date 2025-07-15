
//  妖神之争 １。０
//  by happ@YSZZ 2000.4.15
//  /d/qujing/xuanyuan/npc/bigan.c

inherit NPC;
#include <ansi.h>

void create()
{
  set_name("比干", ({ "bi gan", "bigan" }));
  set("long", "一位身强力壮的中年人。\n");
  set("gender", "男性");
  set("age", 37);
  set("attitude", "heroism");
  set("per", 30);
  set("max_kee", 700);
  set("max_gin", 700);
  set("max_sen", 700);
  set("force", 700);
  set("max_force", 700);
  set("force_factor", 60);
  set("max_mana", 700);
  set("mana", 400);
  set("mana_factor", 60);
  set("combat_exp", 410000);
  set_skill("dodge", 180);
  set_skill("parry", 180);
  set_skill("force", 50);
  set_skill("spells", 50);
  set_skill("unarmed", 50);
  set_skill("staff", 50);
  set_skill("gouhunshu", 50);
  set_skill("tonsillit", 50);
  set_skill("ghost-steps", 50);
  set_skill("jienan-zhi", 50);
  set_skill("lunhui-zhang", 50);
  map_skill("unarmed", "jienan-zhi");
  map_skill("force", "tonsillit");
  map_skill("spells", "gouhunshu");
  map_skill("staff", "lunhui-zhang");
  set("inquiry", ([
        "无心菜": "哈哈，无心菜不能活，我比干能活\n",
        ]));
  setup();
  carry_object("/d/obj/cloth/gongpao")->wear();
  carry_object("/d/qujing/biqiu/obj/ring")->wear();
  carry_object("/d/qujing/biqiu/obj/neck")->wear();
  carry_object("/d/qujing/biqiu/obj/wrists")->wear();
}

void kill_ob (object ob)
{
  set_temp("my_killer",ob);
  ::kill_ob(ob);
  call_out("jiang",2,ob);
}

void die ()
{
   object xin;
   object ob = query_temp("my_killer");
   xin=new("/d/qujing/xuanyuan/obj/xin");
   message_vision (HIR"\n$N摔倒在地，一颗红心扑腾扑腾的跳着。\n"NOR,this_object());
   xin->move(environment(this_object()));
   destruct(this_object());
}

void unconcious ()
{
  die ();
}

void jiang(object ob)
{
        object jiang=new(__DIR__"jiang");
        jiang->move(environment(ob));
        message_vision(HIR"忽一人大喊：留下比干，只见一个道士从天而降。\n"NOR,ob);
}
