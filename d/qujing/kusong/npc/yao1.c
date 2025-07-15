//Cracked by Roath
inherit NPC;
string *namea= ({
  "山猫怪",
  "苍狼怪",
  "野猪怪",
  "棕熊怪",
  "花虎怪",
  "黑蟒怪",
  "巨猿怪",
});


void create()
{
	string name, str;
	int i;
	name=namea[random(sizeof(namea))];

	set_name(name, ({"yao guai", "guai"}));

	i = random(5) + 6;
	set("class", "yaomo");
	set("gender", "男性");
	set("attitude", "heroism");
	set("per", 10);

	set("age", 20+random(40));
	set("max_kee", 100*i);
	set("max_sen", 100*i);
	set("force", 100*i);
	set("max_force", 100*i);
	set("force_factor", 5*i);
	set("mana", 100*i);
	set("max_mana", 100*i);
	set("mana_factor", 5*i);

	set("combat_exp", 20000*i+random(50000));
	
	set("eff_dx", -8000*i);
	set("nkgain", 300);

	set_skill("parry", 10*i);
	set_skill("unarmed", 10*i);
  	set_skill("dodge", 10*i);
  	set_skill("blade", 10*i);
  	set_skill("fork", 10*i);
  	set_skill("sword", 10*i);
  	set_skill("whip", 10*i);
  	set_skill("axe", 10*i);
	set_skill("moshenbu", 5*i);
	map_skill("dodge", "moshenbu");
	setup();
	carry_object("/d/qujing/kusong/obj/tongjia")->wear();
	str="/d/qujing/kusong/obj/weapon0";
	str[strlen(str)-1] = '0'+random(5);
  	carry_object(str)->wield();
	add_money("silver", random(5));
	add_money("coin", random(90));
}

void init()
{
	object ob;
	::init();

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	if(interactive(ob = this_player()) && 
                (string)ob->query("family/family_name")!="火云洞" ){
		call_out("greeting", 10, ob);
		return;
	}
	return;
}

int greeting(object ob)
{
	if( !ob || !visible(ob) || environment(ob) != environment() ){
		return 1;
	}

	command("kill " + ob->query("id"));
	return 1;
}
