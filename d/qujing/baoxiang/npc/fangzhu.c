// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;
void create()
{
  reload("baoxiang_fang_zhu");
  set_name("坊主", ({"fang zhu","zhu"}));
  set("gender", "男性");
  set("combat_exp", 1000);
  set("age", 46);
  set("per", 14);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "1": "/d/qujing/baoxiang/obj/cspitan",
        "2": "/d/qujing/baoxiang/obj/bpitan",
        "3": "/d/qujing/baoxiang/obj/yizi",
        "4": "/d/qujing/baoxiang/obj/zhuozi",
      "5":  "/d/qujing/baoxiang/obj/guatan",
      ]) );
  setup();
  carry_object("/d/qujing/baoxiang/obj/changpao")->wear();
  add_money("silver", 5);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
