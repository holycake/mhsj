// THIS IS PLAYER'S OWN SKILL (write by gslxz@mhsj)
// xgslxz
// 西瓜太郎
// 火云洞第二代弟子
// 3007182
// 男性
// spear
// 夺命西瓜枪





inherit SKILL;

////////////////////////////////

mapping *action = ({

// ZHAOSHI :0

([
"action" :"$N纵身一跃，手中武器一招「西瓜追魂」对准$n的$l斜斜刺出一枪",
"force" :50,
"dodge" :20,
"damage_type": "刺伤",
"lvl" : 0,
"skill_name" : "西瓜追魂"
]),
 });
// ZHAOSHI :1
int valid_learn(object me) { object weapon; if (!objectp(weapon = me->query_temp("weapon"))      || (string)weapon->query("skill_type") != "spear") return notify_fail("你使用的武器不对。\n"); 	if( (int)me->query("max_force") < 50 ) 		return notify_fail("你的内力太弱，无法练"+"夺命西瓜枪"+"。\n"); 	return 1; } int valid_enable(string usage) { return usage=="spear" || usage=="parry"; } string query_skill_name(int level) {         int i;         for(i = sizeof(action)-1; i >= 0; i--)                 if(level >= action[i]["lvl"])                         return action[i]["skill_name"]; } mapping query_action(object me, object weapon) {         int i, level;     level = (int)me->query_skill("dmxg-spear",1);         for(i = sizeof(action); i > 0; i--)                 if(level > action[i-1]["lvl"])                         return action[NewRandom(i, 20, level/5)]; } int practice_skill(object me) { object weapon; if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "spear") return notify_fail("你使用的武器不对。\n");	if( (int)me->query("kee") < 25 ) 		return notify_fail("你的体力不够了，休息一下再练吧。\n"); 	if( (int)me->query("force") < 3 ) 		return notify_fail("你的内力不够了，休息一下再练吧。\n"); 	me->receive_damage("kee", 25); 	me->add("force", -3); 	return 1; } //total 34 lines! 
