// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_zhang_ma");
  set_name("张妈", ({"zhang ma", "zhang", "ma"}));
  set("shop_id", ({"laoban", "zhang ma", "zhang", "ma"}));
  set("shop_title", "瓜果店老板");
  set("gender", "女性");
  set("combat_exp", 3000);
  set("age", 35);
  set("per", 30);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 20);
  set_skill("dodge", 20);
  set_skill("parry", 20);
  set("vendor_goods", ([
        "1": "/d/qujing/tianzhu/obj/bailangua",
        "2": "/d/qujing/tianzhu/obj/mugua",
        "3": "/d/qujing/tianzhu/obj/fanmugua",
        "4": "/d/qujing/tianzhu/obj/juzi",
        "5": "/d/qujing/tianzhu/obj/ganzi",
        "6": "/d/qujing/tianzhu/obj/youzi",
      ]) );

  setup();
  carry_object("/d/obj/cloth/skirt")->wear();
  carry_object("/d/qujing/tianzhu/obj/baojie")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

