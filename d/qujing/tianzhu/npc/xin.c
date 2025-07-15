// by snowcat 12/8/1997


inherit F_VENDOR_SALE;

void create()
{
  reload("tianzhu_xiner_niang");
  set_name("辛儿娘", ({"xiner niang", "xiner", "niang"}));
  set("gender", "女性");
  set("combat_exp", 2000);
  set("age", 28);
  set("per", 21);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 30);
  set("vendor_goods", ([
        "1": "/d/qujing/tianzhu/obj/luweigan",
        "2": "/d/qujing/tianzhu/obj/youzhagan",
        "3": "/d/qujing/tianzhu/obj/chougan",
        "4": "/d/qujing/tianzhu/obj/doufugeng",
        "5": "/d/qujing/tianzhu/obj/lucha",
        "6": "/d/qujing/tianzhu/obj/hongcha",
      ]) );

  setup();
  carry_object("/d/qujing/tianzhu/obj/huaqun")->wear();
  carry_object("/d/qujing/tianzhu/obj/yinjie")->wear();
  carry_object("/d/qujing/tianzhu/obj/yunxue")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

