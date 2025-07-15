// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;

void create()
{
  string dir;
  reload("nuerguo_old_woman");
  set_name("老婆婆", ({"old woman", "woman"}));
  set("shop_id", ({"popo", "woman"}));
  set("gender", "女性" );
  set("age", 65);
  set("long", "一位白发苍苍，满面风霜的老婆婆。\n");
  set("combat_exp", 100);
  set("attitude", "peaceful");
  set("per", 15);
/*
  dir = __DIR__;
  dir[strlen(dir)-4] = 0;
*/
  dir = "/d/qujing/nuerguo/";
  set("vendor_goods", ([
        "2"    : dir+"obj/qiongyao",
        "1"    : dir+"obj/huasheng",
        "3"     : "/d/obj/food/hulu",
      ]));
  setup();
  carry_object("/d/qujing/nuerguo/obj/skirt")->wear();
  add_money ("silver", 2);  
}

void init()
{
  ::init();
  add_action("do_vendor_list", "list");
}

