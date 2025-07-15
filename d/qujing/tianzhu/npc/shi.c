// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_shi_laoban");
  set_name("史老板", ({"shi laoban", "shi", "laoban"}));
  set("shop_id", ({"laoban", "shi"}));
  set("shop_title", "老板");
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "1": "/d/qujing/tianzhu/obj/zhulan",
        "2": "/d/qujing/tianzhu/obj/zhulou",
        "3": "/d/qujing/tianzhu/obj/zhupa",
        "4": "/d/qujing/tianzhu/obj/zhubian",
        "5": "/d/obj/weapon/blade/zhudao",
        "6": "/d/obj/weapon/sword/zhujian",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/baipao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

