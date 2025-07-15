// by gslxz@mhsj 2001/11/21 (优化)
//罗春
#include <ansi.h>
inherit NPC;
void create()
{
  set_name("罗春", ({"luo chun", "luo", "chun", "luochun"}));
  set ("long", @LONG
罗春是罗府的心腹家将，办事甚是得力。传说他是罗艺的私生子，
是罗成的亲哥哥。罗春的一手霸王枪使得纯熟无比，在战场上曾经
颇立战功。
LONG);
  set("title", WHT"罗府家将"NOR);
  set("gender", "男性");
  set("age", 40);
  set("str", 50);
  set("cor", 50);
  set("cps", 50);
  set("spi", 15);
  set("per", 25);
  set("con", 50);
  set("int", 25);
  set("kar", 10);
  set("combat_exp", 3500000);
  set("daoxing", 1000000);
  set_skill("force", 200);
  set_skill("lengquan-force", 200);
  set_skill("parry", 200);
  set_skill("dodge", 200);
  set_skill("yanxing-steps", 200);
  set_skill("unarmed", 200);
  set_skill("changquan", 200);
  set_skill("spear", 200);
  set_skill("bawang-qiang", 200);
  set_skill("spells", 180);
  set_skill("baguazhou", 180);
  map_skill("spells", "baguazhou");
  map_skill("force", "lengquan-force");
  map_skill("unarmed", "changquan");
  map_skill("spear", "bawang-qiang");
  map_skill("parry", "bawang-qiang");
  map_skill("dodge", "yanxing-steps");
  set("max_sen", 1200);
  set("max_kee", 1200);
  set("force", 3000);
  set("max_force", 1800);
  set("force_factor", 60);
        set("max_mana", 3000);
       set("mana", 1500);
       set("mana_factor", 50);
  create_family("将军府", 2, "蓝");
  setup();
 
  carry_object("/d/obj/weapon/spear/tieqiang")->wield();
  carry_object("/d/obj/armor/tiejia")->wear();
}
int accept_fight(object me)
{
  command("say 在这里打架，不怕惊动了楼上的贵人？\n");
  return 0;
}
