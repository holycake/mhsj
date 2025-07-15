//sgzl

inherit NPC;

void create()
{
set_name("雷公",({"lei gong","lei shen","gong"}));
set("gender", "男性");
set("age", 45);
set("long", "    \n一个尖嘴猴腮的天神，在天宫中负责打雷。\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 70000);
  set("daoxing", 120000);


set("kee", 700);
set("max_kee", 700);
set("sen", 750);
set("max_sen", 750);
set("force", 900);
set("max_force", 900);
set("mana", 1100);
set("max_mana", 1100);
set("force_factor", 30);
set("mana_factor", 30);
set("per", 17);


set_skill("dodge", 80);
set_skill("jindouyun", 80);
set_skill("unarmed", 70);
set_skill("puti-zhi", 100);
set_skill("spells", 90);
set_skill("parry", 140);


map_skill("dodge", "jindouyun");
map_skill("unarmed", "puti-zhi");
set("inquiry", ([
  "打雷"   : "急什么？该下雨时我自然会去打雷。",
  "name"   : "我是雷神。",
  "here"   : "这里就是天宫。",
]));


setup();

carry_object("/d/obj/cloth/xianpao")->wear();
carry_object("/d/dntg/sky/obj/leilingfu");

}

