// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  reload("jisaoguo_a_yina");
  set_name("阿依娜", ({"a yina","yina"}));
  set("shop_id",({"yina"}));
  set("gender", "女性" );
  set("age", 22);
  set("per", 25);
  set("long", "一位大眼睛，长辫子的姑娘。\n");
  set("combat_exp", 1000);
  set("max_kee", 300);
  set("max_sen", 300);
  set("attitude", "friendly");
  set("per", 15);
  set("vendor_goods", ([
        "1": "/d/qujing/jisaiguo/obj/silverdagger",
        "2": "/d/qujing/jisaiguo/obj/silverneck",
        "3": "/d/qujing/jisaiguo/obj/silverring",
        "4": "/d/qujing/jisaiguo/obj/silverwrist",
      ]));
  setup();
  add_money ("coin", 50+random(300));
  carry_object("/d/qujing/jisaiguo/obj/changpao")->wear();
}
void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
        add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
        if( !ob || !visible(ob) || environment(ob) != environment() ) return;
        switch( random(3) ) { 
                case 0:
                say(name()+ "笑咪咪地说道：这位" +
RANK_D->query_respect(ob)
                                + "，来给意中人买件银器吧。\n");
                        break;
        }
}

