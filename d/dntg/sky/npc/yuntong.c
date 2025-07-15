//sgzl

inherit NPC;

void create()
{
set_name("云童",({"yun tong","yun shen","tong"}));
set("gender", "男性");
set("age", 15);
set("long", "    \n天宫中负责起云的天神，他虽看上去年纪轻轻，却\n掌管着天上所有的云彩。\n");

set("attitude", "heroism");
set("class", "xian");

    set("combat_exp", 800000);
  set("daoxing", 80000);


  

set("kee", 500);
set("max_kee", 500);
set("sen", 550);
set("max_sen", 550);
set("force", 700);
set("max_force", 700);
set("mana", 900);
set("max_mana", 900);
set("force_factor", 20);
set("mana_factor", 30);
set("per", 22);


set_skill("dodge", 80);
set_skill("jindouyun", 50);
set_skill("unarmed", 70);
set_skill("puti-zhi", 70);
set_skill("spells", 90);
set_skill("parry", 90);


map_skill("dodge", "jindouyun");
map_skill("unarmed", "puti-zhi");
set("inquiry", ([
  "起云"   : "有张灵符可以起云，但我不能给你。",
  "cloud"   : "有张灵符可以起云，但我不能给你。",
  "name"   : "我是云神。",
  "here"   : "这里就是天宫。",
]));


setup();

carry_object("/d/obj/cloth/xianpao")->wear();
carry_object("/d/dntg/sky/obj/yunlingfu");

}

