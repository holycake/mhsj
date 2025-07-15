//Cracked by Roath
// wenshu-pusa

// #include <ansi.h>

inherit NPC;
void create()
{

  set_name("普贤菩萨", ({ "puxian pusa", "pusa", "pu sa", "puxian" }) );
  set("gender", "男性" );
  set("long", @LONG

    普贤，为佛教大乘菩萨之一，它与文殊同为释迦佛的胁侍。传说
，普贤曾在华严法会上发「十大行愿」，佛教尊他为「十大愿王」。
「普贤愿海」成了佛教的老生常谈。但是，普贺菩萨为什麽骑白象呢
？佛经曰，「普贤之学得於行，行之谨审静重莫若象，故好象。」
白象，即意味着它愿行广大，功德圆满。
    
LONG );
  set("age",55);
  set("title", "佛教大乘菩萨");
  set("attitude", "peaceful");
  set("rank_info/self", "贫僧");
  set("class", "bonze");
  set("max_kee", 5000);
  set("max_gin", 5000);
  set("max_sen", 5000);
  set("force", 4000);
  set("max_force", 2000);
  set("force_factor", 145);
  set("max_mana", 3000);
  set("mana", 6000);
  set("mana_factor", 150);
  set("combat_exp", 2000000);
  set("daoxing", 10000000);

  set_skill("literate", 150);
  set_skill("spells", 200);
  set_skill("buddhism", 200);
  set_skill("unarmed", 150);
  set_skill("jienan-zhi", 150);
  set_skill("dodge", 180);
  set_skill("lotusmove", 180);
  set_skill("parry", 180);
  set_skill("force", 180);
  set_skill("lotusforce", 180);
  set_skill("staff", 180);
  set_skill("lunhui-zhang", 180);
  map_skill("spells", "buddhism");
  map_skill("unarmed", "jienan-zhi");
  map_skill("dodge", "lotusmove");
  map_skill("force", "lotusforce");
  map_skill("parry", "lunhui-zhang");
  map_skill("staff", "lunhui-zhang");
  set("chat_chance_combat", 80);
  set("chat_msg_combat", ({
          (: cast_spell, "bighammer" :),
    }) );

  setup();
  carry_object("/d/obj/cloth/hufa-jiasha")->wear();
}
	






