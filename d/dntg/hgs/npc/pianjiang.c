//sgzl

inherit NPC;

void create()
{
set_name("偏将",({"pian jiang","jiang"}));
set("gender", "男性");
set("title", "傲来国");
set("age", 25);
set("long", "    \n一名傲来国的偏将，正在认真的站岗。\n");

set("attitude", "heroism");
set("class", "fighter");
set("combat_exp", 25000);
  set("daoxing", 10000);

set("kee", 400);
set("max_kee", 400);
set("sen", 420);
set("max_sen", 420);
set("force", 350);
set("max_force", 350);
set("mana", 100);
set("max_mana", 100);
set("force_factor", 15);
set("mana_factor", 0);


set_skill("dodge", 50);
set_skill("spells", 30);
set_skill("unarmed", 50);
set_skill("parry", 50);
set_skill("spear", 30);


set("inquiry", ([
]));


setup();

carry_object("/d/obj/weapon/spear/tieqiang")->wield();
carry_object("/d/obj/cloth/bingfu")->wear();

}


void unconcious ()
{
  object ob;
  object me = this_object();
  object where = environment (me);

  message_vision ("\n$N喊到：＂快来人哪！有人劫兵器库啦！＂说罢撒腿跑了出去。\n",me);
  message_vision ("\n另一个$N急急忙忙的赶来。\n",me);
  ob = new (__DIR__"pianjiang");
  ob->move(where);
  destruct (me);
}

void die ()
{
  unconcious();  
}

