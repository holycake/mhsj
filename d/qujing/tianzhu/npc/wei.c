// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_wei_dasao");
  set_name("魏大嫂", ({"wei dasao", "wei", "dasao", "sao"}));
  set("shop_id", ({"dasao", "sao", "wei"}));
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 30);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "1": "/d/qujing/tianzhu/obj/xiancai",
        "2": "/d/qujing/tianzhu/obj/douya",
        "3": "/d/qujing/tianzhu/obj/huacai",
        "4": "/d/qujing/tianzhu/obj/shansun",
        "5": "/d/qujing/tianzhu/obj/mogu",
        "6": "/d/qujing/tianzhu/obj/muer",
      ]) );

  setup();
  carry_object("/d/obj/cloth/linen")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

