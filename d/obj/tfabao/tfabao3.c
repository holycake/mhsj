// 神话世界・西游记・版本（西游世纪）
/* <SecCrypt CPL V3R05> */
// by night
//定身特殊法宝基本文件
#include <ansi.h>
#include <weapon.h>

inherit ITEM;

int ji(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);

/************************************************************/

void create()
{
    set_name(YEL "定身类法宝" NOR,({"fabao object", "fabao", "object"}));
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
	set("long","一只用来捆人的法宝。\n");
	}
    setup();
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar()/2, dingtime, condition;
    string msg, fabaoname=this_object()->name();

    if (this_object()->query("in_use"))
   	return notify_fail("你现在正在使用"+fabaoname+"。\n");
    
    if (!target)
	return notify_fail("你想用对谁用"+fabaoname+"？\n");

    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("这里没有 "+target+"。\n");

    if (me->is_busy())
    {
    	tell_object (me, "你无法忙中偷闲祭"+fabaoname+"。\n");
        return notify_fail("你正忙着呢。\n");
    }
  
    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting(victim))
	return notify_fail("只有战斗中才能祭"+fabaoname+"。\n");  
    if(victim->query("no_move"))
   	return notify_fail("对方已经无暇自顾了，有必要用"+fabaoname+"么？\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");

    msg=HIC"$N从背后抽出一"+this_object()->query("unit")+fabaoname+HIC"，向空抛起，口中念念有词，\n"NOR;
    if (this_object()->query("interactive_usage") > (me->query_kar()/3))
    {
    message_vision ("只见"+fabaoname+"在天上化为一片烟雾，被风吹散了。\n",me);
    destruct (this_object());
    return notify_fail("你祭"+fabaoname+"失败。\n");
    }
    switch( random(3))   {
    case 0:	
    msg+=RED"红光一闪，"+fabaoname+RED"中飞出一条蛟龙，向$n"RED"扑去。\n"NOR;
    break;
    case 1:
    msg+=CYN"只见"+fabaoname+CYN"在空中一个转折，仿佛有灵性般，向$n"CYN"缠绕而去。\n"NOR;
    break;
    case 2:
    msg+=YEL"金光耀目，只见"+fabaoname+YEL"化为一片黄云，向$n"YEL"当头罩下。\n"NOR;
    break;
    }
    
    // if condition is 1, then ji is successful.
    // if condition is 0, then ji is unsuccessful but nothing bad happens.
    // if condition is -1, then ji fails AND is bounced back.

    condition=determine_success(me, victim);
    switch(condition)
    {
    case 1:
    msg+=HIR"$n"HIR"被牢牢缚住，一时间手忙脚乱，不知所措。\n" NOR;
    msg+=CYN"$n"CYN"被"+fabaoname+CYN"的法力定住了！\n"NOR;
    victim->set_temp("no_move", 1);
    dingtime=random(mykar);
    if (dingtime < 1) dingtime=1; 
    if (wizardp(me) && me->query("env/combat")=="verbose")
       tell_object(me, GRN ""+victim->name()+"被定住了"+chinese_number(dingtime)+"秒。\n" NOR);
    this_object()->set("in_use", 1);
    call_out("remove_ding", dingtime, me, victim);
    break;
    case 0:
    msg+=HIB"$n"HIB"伸手一指，大喝一声“落！”只见金光闪过，"+fabaoname+HIB"落回了$N"HIB"手中。\n"NOR;
    break;
    case -1:
    msg+=HIB"$n"HIB"伸手一指，大喝一声“回！”，只见"+fabaoname+HIB"在空中一个盘旋，反将$N"HIB"缠住了！\n"NOR;
    dingtime=random(victim->query_kar()/2);
    if (dingtime<1) dingtime=1;
    me->set_temp("no_move",1);
    this_object()->set("in_use",1);
    call_out("remove_ding", dingtime, victim, me);
    break;
    case -2:
    msg+=HIB"$n"HIB"伸手一指，大喝一声“收！”只见"+fabaoname+HIB"从空中软软地落下，掉入$n"HIB"手中。\n"NOR;
    this_object()->move(victim);
    break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    this_object()->add("interactive_usage",1);    
    me->start_busy(random(3)+1);    
    return 1;
}        

void remove_ding(object me, object victim)
{
    string msg=CYN"只见"+query("name")+CYN"腾空而起，回到了$N"CYN"手中。\n"NOR;
    this_object()->delete("in_use");
    
    if(!victim) return;

    if (living(victim))
    msg += CYN"$n"CYN"又恢复了自由。\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}

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

    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();

    cost=me->query(variable)/4;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

