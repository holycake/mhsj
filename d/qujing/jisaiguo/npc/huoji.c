// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("jisaiguo_huoji");
  set_name("伙计", ({"huoji"}));
  set("shop_id", ({"huoji"}));
  set("shop_title", YEL"小伙计"NOR);
  set("gender", "男性" );
  set("age", 18);
  set("per", 25);
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
  set("vendor_goods", ([
        "1": "/d/qujing/jisaiguo/obj/zhulou",
        "2": "/d/lingtai/obj/shaoba",
        "3": "/d/obj/weapon/sword/zhujian",
        "4": "/d/obj/weapon/blade/zhudao",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/obj/cloth/linen")->wear();
}
void init()
{
  ::init();
        add_action("do_vendor_list", "list");
}
