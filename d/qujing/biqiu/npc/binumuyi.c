// by snowcat oct 15 1997

inherit F_VENDOR_SALE;

void create()
{
  reload("biqiu_binu_muyi");
  set_name("碧奴慕伊", ({"binu muyi", "muyi", "boss"}));
  set("shop_id", ({"muyi"}));
  set("gender", "女性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "1": "/d/obj/misc/hualan",
        "2": "/d/obj/misc/vase",
      ]) );

  setup();
  carry_object("/d/obj/cloth/nichang")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
