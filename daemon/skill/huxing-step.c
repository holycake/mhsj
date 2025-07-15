// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
inherit SKILL;

string *dodge_msg = ({
        "$n一式「天外飞狐」身形急转，跃了起来．\n",
   "$n一伏身，身体象泥鳅一般，滑出两丈开外。\n",
   "只见$n身体一晃，一个「神狐再现」，轻轻的躲开。\n",
   "$n一声狐鸣，$N顿时举手无措，$n趁机闪在一旁。\n",
"$n忽然对$N一声媚笑，$N顿时忘记了自己身处战斗之中。\n",
});

int valid_enable(string usage)
{
        return (usage=="dodge");
}


string query_dodge_msg(string limb)
{
        return dodge_msg[random(sizeof(dodge_msg))];
}

int practice_skill(object me)
{
        if( (int)me->query("kee") < 30
        ||      (int)me->query("force") < 3 )
                return
notify_fail("你的气或内力不够，不能练雁行步法。\n");
        me->receive_damage("kee", 30);
        me->add("force", -3);
        return 1;
}

