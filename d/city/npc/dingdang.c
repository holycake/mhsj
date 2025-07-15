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
             "shendan":"/clone/mohuan/shendan",
             "jnz":"/clone/mohuan/jnz",
 "xiandan":"/clone/mohuan/xiandan",
 "555":"/clone/555",
 "xieyao":"/clone/xieyao",
 "pigu":"/clone/dan",
 "bag":"/u/gslxz/obj/bag",
 "rongmao":"/clone/perwan",
 "neili":"/clone/neili",
  "karwan":"/clone/karwan",
   "piduzhu":"/clone/zhu",
                    "qingting":"/clone/mohuan/qingting",
                    "shenliwan":"/clone/shenliwan",
                    "xiandan":"/clone/xiandan",
                    "xisuidan":"/clone/xisuidan",
                    "unknowdan":"/clone/unknowdan",
                "xianyao":"/u/gslxz/obj/jinchuang",
                     "shenyao":"/u/gslxz/obj/hunyuandan",
 "pan":"/d/city/npc/obj/pan",
   "wan":"/clone/mohuan/sq",
]) );
        
              setup();
        carry_object("/d/obj/cloth/cloth")->wear();
        
}

void init()
{
        ::init();
              add_action("do_vendor_list", "list");
}
