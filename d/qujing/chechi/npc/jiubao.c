// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("chechi_jiu_bao");
  set_name("酒保", ({"jiu bao", "jiubao", "bao"}));
  set("shop_id", ({"jiubao", "jiu bao", "bao"}));
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "1": "/d/qujing/chechi/obj/roujia",
        "2": "/d/qujing/chechi/obj/niurou",
        "3": "/d/qujing/chechi/obj/baiye",
        "4": "/d/qujing/chechi/obj/jiuhu",
      ]) );

  setup();
  carry_object("/d/qujing/chechi/obj/changpao")->wear();
  add_money("silver", 10);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

