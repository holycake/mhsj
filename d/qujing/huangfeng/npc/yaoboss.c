// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("huangfeng_doctor_huangfeng");
  set_name("王老板", ({"wang laoban", "wang", "laoban"}));
  set("shop_id", ({"laoban", "wang","wang laoban" }));
  set("shop_title", "郎中");
  set("gender", "男性");
  set("combat_exp", 50000);
  set("age", 48);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("dodge", 30);
  set_skill("parry", 30);
  set("vendor_goods", ([
        "1": "/d/qujing/tianzhu/obj/wan",
        "2": "/d/qujing/tianzhu/obj/fen",
        "3": "/d/qujing/tianzhu/obj/dan",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
  carry_object("/d/qujing/tianzhu/obj/simao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

