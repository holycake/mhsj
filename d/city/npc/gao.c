#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void clear_room();

void create()
{
         set_name(NOR+WHT"高老板"NOR, ({"gao laoban","gao","laoban","boss"}));
         set("title",YEL"長安首富"NOR);
       set("gender", "男性");
        set("combat_exp", 1000);
       set("age", 26);
       set("str", 57);
       set("food", 1200);
       set("water", 1200);
       set("per", 30);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 10);
       set("max_price",20);
        set("vendor_goods", ([
           "shendan":"/clone/mohuan/shendan",
           "xiandan":"/clone/mohuan/xiandan",
             "pidudan":"/clone/pidudan",
             "piduzhu":"/clone/piduzhu",
  "bag":"/u/gslxz/obj/bag",
//    "xisui":"/clone/xisuidan",
//    "shenli":"/clone/shenliwan",
  "rongmao":"/clone/perwan",
    "xianxing":"/clone/xianxing",
      "tance":"/adm/cl/tance",
"pigu":"/clone/dan",
"xieyao":"/clone/xieyao",
"qingting":"/clone/mohuan/qingting",
"jnz":"/clone/mohuan/jnz",
                "xianyao":"/u/gslxz/obj/jinchuang",
                     "shenyao":"/u/gslxz/obj/hunyuandan",
 "pan":"/d/city/npc/obj/pan",
   "wan":"/clone/mohuan/sq",
]) );
        
              setup();
 carry_object("/d/city/npc/obj/choupao")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
