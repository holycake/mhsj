// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>

inherit F_VENDOR_SALE;

void create()
{
  reload("wuji_ye_dasao");
  set_name("叶大嫂", ({"ye dasao", "ye", "dasao", "fruit vendor"}));
  set("shop_id", ({"dasao"}));
  set("shop_title", HIG"水果店大嫂"NOR);
  set("gender", "女性");
  set("combat_exp", 1000);
  set("age", 26);
  set("per", 20);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set("vendor_goods", ([
    "1": "/d/obj/food/grape",
    "2": "/d/obj/food/xueli",
    "3": "/d/obj/food/strawberry",
    "4": "/d/obj/food/apple",
    "5": "/d/obj/food/mellon",
   ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  add_money("silver", 1);
}

void init()
{
  object ob;

  ::init();
  if( interactive(ob = this_player()) && !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting", 1, ob);
  }
  add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
  if( !ob || !visible(ob) || environment(ob) != environment() ) return;
  switch( random(3) ) {  // 1/3 chance to greet.
    case 0:
      say ("叶大嫂笑咪咪地说道：这位" + RANK_D->query_respect(ob)
           + "，欢迎惠顾四季瓜果店！\n");
      break;
  }
}

