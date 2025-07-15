// by gslxz@mhsj 2001/12/1 (优化)
#include <ansi.h>
inherit F_VENDOR_SALE;
void create()
{
  reload("wang");
  set_name("王大嫂", ({"wang dasao", "sao", "dasao"}));
  set("title",HIM"糖葫芦店"NOR WHT"老板娘"NOR);
  set("gender", "女性");
  set("age", 32);
  set("long","一位长得很仁慈的中年妇女。\n");
  set("attitude", "peaceful");
  set("combat_exp", 15000);
	set("daoxing",15000);	
  set_skill("dodge", 30);
  set("vendor_goods", ([
            "1" : "/d/jz/obj/tang",
            "2"  : "/d/jz/obj/wan",
                      ]));
  setup();
  carry_object("/d/obj/cloth/linen")->wear();
  add_money("coin", 100);
}
void init()
{
  ::init();
  add_action("do_vendor_list", "list");

}
