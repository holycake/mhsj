#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
       set_name(HIW"小叮当"NOR, ({"dingdang"}));
       set("title",HIB"二十二世纪的机器人"NOR);
       set("gender", "男性");
        set("combat_exp", 1000);
       set("age", 26);
       set("per", 14);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
             "1":"/clone/mohuan/shendan",
             "2":"/clone/mohuan/jnz",
 "3":"/clone/mohuan/xiandan",
 "4":"/clone/xieyao",
 "5":"/clone/dan",
 "6":"/u/gslxz/obj/bag",
 "7":"/clone/perwan",
  "9":"/clone/karwan",
     "10":"/clone/piduzhu",
                    "11":"/clone/mohuan/qingting",
                "12":"/u/gslxz/obj/jinchuang",
                     "13":"/u/gslxz/obj/hunyuandan",
 "14":"/d/city/npc/obj/pan",
   "15":"/clone/mohuan/sq",
]) );
        
              setup();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
