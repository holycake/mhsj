#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
        set_name("萧萧", ({"xiao xiao", "xiao"}));
   set("title", HIY"惡娘子"NOR);
   set("gender", "女性");
set("long", "老英雄萧振远的小女儿，兵器铺女老板。\n由于凶蛮狠毒，江湖人称＂恶娘子＂。\n");
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
  "1":"/clone/armor/fenghuang",
          "2":"/clone/armor/fork",
            "3":"/clone/armor/whip",
       "4":"/clone/armor/hammer",
            "5":"/clone/armor/bang",
    "6":"/clone/armor/blade",
     "7":"/clone/armor/sword",
 "8":"/clone/armor/staff",
     "9":"/clone/armor/spear",
      "10":"/clone/armor/mace",
]) );
        
              setup();
//    carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
