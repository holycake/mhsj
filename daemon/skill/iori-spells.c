// buddhism.c

inherit SKILL;

int valid_enable(string usage) { return usage=="spells"; }

int valid_learn(object me)
{
        if( (int)me->query_skill("spells") <= (int)me->query_skill("iori-spells") )
                return notify_fail("你的法术修为还不够高深，无法学习冰矢之法\n");
        if( (int)me->query("bellicosity") < 100 )
                return notify_fail("你的杀气太低，无法修炼冰矢之法。\n");
        return 1;
}

string cast_spell_file(string spell)
        {
return CLASS_D("kof") + "/iori-spells/" + spell;

        }

string type() { return "magic";}


