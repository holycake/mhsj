// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("baoxiang_lao_ban");
  set_name("老板", ({"laoban"}));
  set("shop_id", ({"laoban"}));
  set("shop_title", "老板");
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "1": "/d/qujing/baoxiang/obj/yangtou",
        "2": "/d/qujing/baoxiang/obj/paomo",
        "3": "/d/qujing/baoxiang/obj/zasui",
      ]) );

  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 10);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

