// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_shu_laoban");
  set_name("舒老板", ({"shu laoban", "shu", "laoban"}));
  set("shop_title", "老板");
  set("shop_id", ({"laoban", "shu"}));
  set("gender", "男性");
  set("combat_exp", 9000);
  set("age", 50);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set_skill("parry", 30);
  set_skill("dodge", 30);
  set("vendor_goods", ([
    "1" : "/d/qujing/tianzhu/obj/piyi",
    "2" : "/d/qujing/tianzhu/obj/pidun",
    "3" : "/d/qujing/tianzhu/obj/pixue",
    "4" : "/d/qujing/tianzhu/obj/pimao",
   ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/pixue")->wear();
  carry_object("/d/qujing/tianzhu/obj/piyi")->wear();
  carry_object("/d/qujing/tianzhu/obj/pimao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

