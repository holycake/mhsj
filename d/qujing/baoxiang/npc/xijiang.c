// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("baoxiang_xi_jiang");
  set_name("锡匠", ({"xi jiang","jiang"}));
  set("shop_id", ({"xijiang"}));
  set("gender", "男性");
  set("combat_exp", 1000);
  set("age", 35);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "1": "/d/qujing/baoxiang/obj/xihu",
        "2": "/d/qujing/baoxiang/obj/xiwan",
        "3": "/d/qujing/baoxiang/obj/xipen",
      ]) );

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 15);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

