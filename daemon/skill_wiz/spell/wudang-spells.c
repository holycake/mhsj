// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

// taoism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if(me->query("class") == "bonze")
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
			+"即入佛门，怎么却来学道家心法？\n");
	
       if( (int)me->query_skill("spells") <= (int)me->query_skill("buddhism") )
		return notify_fail("你的法术修为还不够高深，无法学习武当仙法。\n");
	
       if( (int)me->query("bellicosity") > 100 )
		return notify_fail("你的杀气太重，无法修炼武当仙法。\n");
		
	return 1;
}

string cast_spell_file(string spell)
	{
return CLASS_D("wudang") + "/wudang-spells/" + spell;

	}

