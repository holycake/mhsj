// by snowcat 12/8/1997

inherit F_VENDOR_SALE;

void create()
{
  reload ("kaifeng_hai");
  set_name("海老板", ({"hai laoban", "hai", "laoban"}));
  set("shop_id",({"laoban","waiter"}));
  set("gender", "男性");
  set("combat_exp", 5000);
  set("age", 48);
  set("per", 24);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 50);
  set_skill("dodge", 50);
  set_skill("parry", 50);
  set("vendor_goods", ([
        "1": "/d/kaifeng/obj/dutiao",
        "2": "/d/kaifeng/obj/ganjian",
        "3": "/d/kaifeng/obj/changtou",
        "4": "/d/kaifeng/obj/feipian",
      ]) );
  setup();
  carry_object("/d/obj/cloth/choupao")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

