// muren.c 木人

inherit NPC;
inherit F_CLEAN_UP;

void create()
{
	set_name("木人", ({ "mu ren", "mu", "wood man", "wood" }) );
	set("gender", "男性" );
	set("age", 30);
	set("long", "一个练功用的比武木人，制作精巧，如同真人一般。\n");
	set("attitude", "heroism");

	set("str", 25);
	set("cor", 25);
	set("cps", 25);
	set("int", 25);

	set("max_kee", 300);
	set("max_gin", 100);
	set("max_force", 300);
	set("jiali", 10);

	set("combat_exp", 50000);

	set_skill("force", 30); 
	set_skill("unarmed", 30);
	set_skill("dodge", 30);
	set_skill("parry", 30);

	set("fight_times", 0);	

	setup();
        
}

int accept_fight(object ob)
{
	object me;
	mapping hp_status, skill_status, map_status;
	string *sname, *mname;
	int i;

	me = this_object();

	if (is_fighting()) return 0;

	if (me->query("damaged"))
		return notify_fail("这个木人已经被打坏了！\n");	

	if (random(me->query("fight_times")) >= 10) {
		me->set("damaged", 1);
		return notify_fail("这个木人已经被打坏了！\n");	
	}

	if (me->query("last_fighter") == ob->query("id"))
		return notify_fail("你刚跟这个木人练过功！\n");		

	me->set("last_fighter", ob->query("id"));
	me->add("fight_times", 1);

	remove_call_out("renewing");	
	call_out("renewing", 300 + random(300), me);	

	me->delete_skill("unarmed");
	me->map_skill("unarmed");
	me->map_skill("dodge");
	me->map_skill("parry");

	if ( !(skill_status = ob->query_skills()) ) return 1;
	sname  = keys(skill_status);

	for(i=0; i<sizeof(skill_status); i++) {
		me->set_skill(sname[i], skill_status[sname[i]]);
	}
	
	if ( !(map_status = ob->query_skill_map()) ) return 1;
	mname  = keys(map_status);

	for(i=0; i<sizeof(map_status); i++) {
		me->map_skill(mname[i], map_status[mname[i]]);
	}
	
	hp_status = ob->query_entire_dbase();

		me->set("str", hp_status["str"]);
		me->set("int", hp_status["int"]);
		me->set("con", hp_status["con"]);
		me->set("dex", hp_status["dex"]);

		me->set("max_kee",    hp_status["max_kee"]);
		me->set("eff_kee",    hp_status["eff_kee"]);
		me->set("kee",        hp_status["kee"]);
		me->set("max_gin",  hp_status["max_gin"]);
		me->set("eff_gin",  hp_status["eff_gin"]);
		me->set("gin",      hp_status["gin"]);
		me->set("max_sen",  hp_status["max_sen"]);
		me->set("eff_sen",  hp_status["eff_sen"]);
		me->set("sen",      hp_status["sen"]);
		me->set("max_force", hp_status["max_force"]);
		me->set("force",     hp_status["force"]);
		me->set("enforce",     hp_status["enforce"]);
		me->set("combat_exp",hp_status["combat_exp"]);

	return 1;
}

void renewing(object me)
{
	me->delete("last_fighter");
}
