// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;
void create()
{
  reload("tongtian_chen_sanxian");
  set_name("陈三鲜", ({"chen sanxian","chen"}));
  set("title", "水鲜贩子");
  set("gender", "男性");
  set("combat_exp", 500);
  set("age", 30);
  set("per", 34);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 100);
  set("vendor_goods", ([
        "1":"/d/qujing/tongtian/obj/zhengxie",
        "2":"/d/qujing/tongtian/obj/shaoxia",
        "3":"/d/qujing/tongtian/obj/xunyu",
        "4":"/d/qujing/tongtian/obj/zuiluo",
      ]) );
  setup();
  carry_object("/d/obj/cloth/changpao")->wear();
  add_money("silver", 5);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
