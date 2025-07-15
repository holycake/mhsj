//Cracked by Roath
inherit NPC;
string *namea= ({
  "鹿头怪",
  "狐头怪",
  "马头怪",
  "羊头怪",
  "兔头怪",
});


void create()
{
	string name;
	int i;
	name=namea[random(sizeof(namea))];

	set_name(name, ({"yao guai", "guai"}));

	i = random(5) + 6;
	set("class", "yaomo");
	set("gender", "女性");
	set("per", 20+random(10));
	set("age", 20);
	set("max_kee", 70*i);
	set("max_sen", 70*i);
	set("force", 30*i);
	set("max_force", 30*i);
	set("force_factor", 3*i);
	set("mana", 30*i);
	set("max_mana", 30*i);
	set("mana_factor", 3*i);

	set("combat_exp", 5000*i+random(5000));
	
	set("eff_dx", -1500*i);
	set("nkgain", 200);

	set_skill("parry", 7*i);
	set_skill("unarmed", 7*i);
  	set_skill("dodge", 7*i);
	set_skill("moondance", 3*i);
	set_skill("baihua-zhang", 3*i);
	map_skill("unarmed", "baihua-zhang");
	map_skill("dodge", "moondance");
	setup();

	carry_object("/obj/loginload/shoes")->wear();
	carry_object("/obj/loginload/skirt")->wear();
	add_money("silver", random(5));
	add_money("coin", random(90));

}

