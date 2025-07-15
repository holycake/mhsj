// 神话世界・西游记・版本（西游世纪）
/* <SecCrypt CPL V3R05> */
// by night
//逃跑特殊法宝基本文件
#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int ji();
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
object offensive_target(object me);
/************************************************************/

void create()
{
    set_name(YEL "逃跑类法宝" NOR,({"fabao object", "fabao", "object"}));
    set_weight(10000);
    if(clonep())
        set_default_object(__FILE__);
    else {
        set("value", 1);
        set("no_get", 1);       
        set("no_give", 1);      
        set("no_sell", 1);      
        set("no_drop", 1);      
        set("no_put", 1);
        set("material","jade");

        set("long","一只用来逃跑的法宝。\n");
        }
    setup();
}

// This function selects a random target for offensive spells/functions.
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int ji()
{
    object victim;
    int sp;
    object me=this_player();
    int mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name(), unit=this_object()->query("unit");

    string *ACTIONS=({HIW"掏出一"+unit+objname+HIW"，向空中抛起，口中念念有词，\n"NOR,
                      HIY"手一挥，霞光闪过，一"+unit+objname+HIY"飞到半空，盘旋飞舞，\n"NOR,
                      HIR"将一"+unit+objname+HIR"铺开，"+objname+HIR"一边旋转，一边越变越大，\n"NOR,
                      HIC"一声呼哨，忽然电光一闪，一"+unit+objname+HIC"从空中徐徐降下，\n"NOR,
                      HIB"双手一合，只见浓重的雾气平空涌出，接着，一"+unit+objname+HIB"忽然出现在雾里，\n"NOR,
                      });
    string *RESULTS=({HIW"只见一股烟雾卷起，将$N裹在当中。\n"NOR,
                      HIY"只见一道亮光闪过，$N的整个身体都被亮光笼罩了。\n"NOR,
                      HIR"只见一道金光迸射，$N蓦地消失在"+objname+HIR"中。\n"NOR,
                      HIC"只听一声霹雳响过，$N的身体开始快速地旋转起来，逐渐升到半空。\n"NOR,
                      HIB"只见一片水雾迷朦，$N的身影在雾气中逐渐淡去。\n"NOR,
                      });    
    if( me->is_busy())
        return notify_fail("你正忙着呢，先应付眼前的事吧。\n");

    if( (int)me->query("mana") < 100)
        return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 50)
        return notify_fail("你的精神无法集中！\n");
    if((!environment(me)->query("valid_startroom")
    || !environment(me)->query("sleep_room")
    || !environment(me)->query("no_fight"))
    && (int)me->query("sen") * 100 / (int)me->query("max_sen") > 50 
    && (int)me->query("kee") * 100 / (int)me->query("max_kee") > 50)
        return notify_fail("你现在体力充沛，精神充足，只能在安全区使用"+objname+NOR+"。\n");
    
    sp = random(5); 
    victim = offensive_target(me);
    msg = ACTIONS[sp];
    msg += RESULTS[sp];
    if(!victim)
    {
      if(!me->is_fighting())
      {	
      switch( sp )   {
	case 0:
       	message_vision(HIW"$N"+msg,me);
       	break;
       	case 1:
       	message_vision(HIY"$N"+msg,me);
	break;
	case 2:
       	message_vision(HIR"$N"+msg,me);
       	break;
	case 3:
       	message_vision(HIC"$N"+msg,me);
       	break;
	case 4:
       	message_vision(HIB"$N"+msg,me);
       	break;
	}
      me->add("mana",-100);
      me->add("sen",-50);
      me->move("/d/city/kezhan");
      message_vision(YEL"$N忽然出现在大家面前。\n"NOR,me);
      return 1;
      }
    }

    switch( sp )   {
	case 0:
       	message_vision(HIW"激战中，$N忽然跳出战圈，"+msg,me);
       	break;
       	case 1:
       	message_vision(HIY"激战中，$N忽然跳出战圈，"+msg,me);
	break;
	case 2:
       	message_vision(HIR"激战中，$N忽然跳出战圈，"+msg,me);
       	break;
	case 3:
       	message_vision(HIC"激战中，$N忽然跳出战圈，"+msg,me);
       	break;
	case 4:
       	message_vision(HIB"激战中，$N忽然跳出战圈，"+msg,me);
       	break;
       	}
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    
    condition=determine_success(me, victim);

    switch(condition)
    {
      case 1:
        message_vision(HIR"$n眼前一暗，$N已经不见了。\n"NOR,me,victim);
        me->move("/d/city/kezhan");
    	message_vision(YEL"$N忽然出现在大家面前。\n"NOR,me);        
        break;
      case -1:
        message_vision(HIB"但$n大喝一声，运起法力，将手一指，$N立刻无所遁形。\n"NOR,me,victim);
    	break;
    }
    me->add("mana", -determine_cost("mana", 100));
    me->add("sen", -determine_cost("sen", 40));
    return 1;
}

/************************************************************/
int determine_success(object me, object victim)
{
    int myspells, myexp, victimspells, victimexp;
    int ap, dp, attackfactor, condition;

    myspells=me->query_skill("spells")/10;
    myexp=me->query("combat_exp")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimexp=victim->query("combat_exp")/1000;

    ap=(myexp+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimexp+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;

    attackfactor=random(ap+dp);

    if (attackfactor>dp/4) condition=1;
    else condition=-1;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    // nothing complicated here i think.

    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}
/************************************************************/
