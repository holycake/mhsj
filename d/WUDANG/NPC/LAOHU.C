// laofu.c 老虎
// Date: Sep.22 1997
#include <ansi.h>;
inherit NPC;

void create()
{
        set_name("老虎", ({ "laohu", "tiger","hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", @LONG
一只斑斓猛虎，雄伟极了。

         _.-'"''--..__.("\-''-'")
 ('.__.-' (  *  ) .-'    ( @ _@'
  `-..-''.' _.'  (   _.  `(._Y_)
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)



LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "老虎在浚巡，吓得你大气都不敢出。\n",
                "老虎仰天长啸，声震山谷，黄叶纷坠。\n",
        }) );
}

