// by snowcat 12/8/1997

inherit F_VENDOR_SALE;

void create()
{
  reload("kaifeng_cha");
  set_name("茶娘子", ({"chaniang zi", "niang zi", "niang", "zi"}));
  set("gender", "女性");
  set("combat_exp", 3000);
  set("age", 38);
  set("per", 29);
  set("attitude", "friendly");
  set("shen_type", 1);
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
  set("vendor_goods", ([
        "1": "/d/kaifeng/obj/chagan",
        "2": "/d/kaifeng/obj/chahu",
      ]) );
  setup();
  carry_object("/d/obj/cloth/pink_cloth")->wear();
  carry_object("/d/obj/cloth/shoes")->wear();
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

