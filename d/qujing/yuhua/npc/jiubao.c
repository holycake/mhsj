// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("yuhua_jiu_bao");
  set_name("酒保", ({"jiu bao", "jiubao", "bao"}));
  set("shop_id", ({"jiubao", "bao"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 30);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "1": "/d/qujing/yuhua/obj/pig",
        "2": "/d/qujing/yuhua/obj/lamb",
        "3": "/d/obj/food/baijiu",
	"4": "/d/ourhome/obj/jitui",
        "5": "/d/obj/food/jiunang",
      ]) );

  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}
