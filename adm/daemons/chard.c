// chard.c
#include <ansi.h>
#include <race.h>
#include <skill.h>
#include <ansi.h>
int victim_lose(object killer,object victim,string killerid);
void create() { seteuid(getuid()); }
 string line, str, skill_type, *marks,name1,name2,ob,me,arg;
void setup_char(object ob)
{
	string race;
	mapping my;

	if( !stringp(race = ob->query("race")) ) {
		race = "人类";
		ob->set("race", "人类");
	}

	switch(race) {
		case "赛亚人":
		case "人类":
			HUMAN_RACE->setup_human(ob);
			break;
		case "妖魔":
			MONSTER_RACE->setup_monster(ob);
			break;
		case "野兽":
			BEAST_RACE->setup_beast(ob);
			break;
		default:
			error("Chard: undefined race " + race + ".\n");
	}

	my = ob->query_entire_dbase();

	if( undefinedp(my["gin"]) ) my["gin"] = my["max_gin"];
	if( undefinedp(my["kee"]) ) my["kee"] = my["max_kee"];
	if( undefinedp(my["sen"]) ) my["sen"] = my["max_sen"];

	if( undefinedp(my["eff_gin"]) ) my["eff_gin"] = my["max_gin"];
	if( undefinedp(my["eff_kee"]) ) my["eff_kee"] = my["max_kee"];
	if( undefinedp(my["eff_sen"]) ) my["eff_sen"] = my["max_sen"];

	if( !ob->query_max_encumbrance() )
//		ob->set_max_encumbrance( my["str"] * 5000 );
		ob->set_max_encumbrance( my["str"]*5000 +
                    (int)ob->query_skill("unarmed",1)*200);
	ob->reset_action();
}

varargs object make_corpse(object victim, object killer)
{
	int i;
	object corpse,corpse1, *inv;

	if( victim->is_ghost() ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) inv[i]->move(environment(victim));
		return 0;
	}
	corpse = new(CORPSE_OB);
	corpse1 = new(CORPSE_OB);
	corpse->set_name( victim->name() + "的尸体", ({ "corpse" }) );

           corpse->set("long", victim->long()
		+ "然而，" + gender_pronoun(victim->query("gender")) 
		+ "已经死了，只剩下一具尸体静静地躺在这里。\n");
	corpse->set("age", victim->query("age"));
	corpse->set("gender", victim->query("gender"));
	corpse->set("victim_name", victim->name(1));
	corpse->set_weight( victim->query_weight() );
	corpse->set_max_encumbrance( victim->query_max_encumbrance() );
	corpse->move(environment(victim));
 
	// Don't let wizard left illegal items in their corpses.
          
	
	if( !wizardp(victim) ) {
		inv = all_inventory(victim);
		inv->owner_is_killed(killer);
		inv -= ({ 0 });
		i = sizeof(inv);
		while(i--) {
			if( (string)inv[i]->query("equipped")=="worn" ) {
				inv[i]->move(corpse);
				if( !inv[i]->wear() ) inv[i]->move(environment(victim));
			}
			else inv[i]->move(corpse);
		}
	}

	return corpse;
}

varargs object make_toulu(object corpse)
{
        object toulu;
        toulu=new("/clone/misc/toulu");
        toulu->set("name",(string)corpse->query("oldname")+"的头颅");
        toulu->set("gender",corpse->query("gender"));
        toulu->set("age",corpse->query("age"));
        return toulu;
}
varargs object make_wutoucorpse(object corpse)
{
        string name,oldname;
        sscanf(corpse->query("name"),"%s的尸体%*s",oldname);
        corpse->set("oldname",oldname);
        switch(corpse->query("gender"))
        {
        case "男性":
                name="无头男尸";
                break;
        case "女性":
                name="无头女尸";
                break;
        default:
                name="性别不明的尸体";
                break;
        }

        corpse->set("name",name);
        corpse->set("id",({"wutou corpse"}));
        return corpse;
}
