// 神话世界・西游记・版本（西游世纪）
/* <SecCrypt CPL V3R05> */
// by night
//收取特殊法宝基本文件
#include <ansi.h>
#include <weapon.h>
 
inherit ITEM;

int ji (string target);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
 
void create()
{
  set_name("收取类法宝",({"fabao object", "fabao", "object"}));
  set_weight(5000);
  if(clonep())
    set_default_object(__FILE__);
  else {
    set("value", 1);
    set("no_get", 1);	
    set("no_give", 1);	
    set("no_sell", 1);	
    set("no_drop", 1);	
    set("no_put", 1);
    set_max_encumbrance(50000);
    set("material","jade");
    set("long","一只收敌人兵器铠甲的法宝。\n");
  }
  setup();
} 

int ji_ob (object victim)
{
  object fabao = this_object ();
  object me = environment(fabao);
  string fabaoname = fabao->query("name");
  object ob;
  int mykar=me->query("kar"), victimkar;
  int condition;

  if (me->is_busy())
  {
    tell_object (me, "你无法忙中偷闲祭"+fabaoname+"。\n");
    return notify_fail("你正忙着呢。\n");
  }

  if (sizeof(all_inventory(fabao))>0)
  {
    tell_object (me, fabaoname+"里有杂物，你无法再祭"+fabaoname+"。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  if (!victim)
  {
    tell_object (me, "你想祭的人不在这里。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  if (!living(victim))
  {
    tell_object (me, victim->query("name")+"已经毫无抵抗能力了。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  if (!me->is_fighting())
  {
    tell_object (me, "只有战斗中才能祭"+fabaoname+"。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  if ((int)me->query("mana") < 300)
  {
    tell_object (me, "你的法力不足，祭不了"+fabaoname+"。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  if( (int)me->query("sen") < 300)
  {
    tell_object (me, "你无法集中精神念咒语。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  ob = victim->query_temp("weapon"); 
  if(!ob)
  {
    tell_object (me, "对方没有使用武器。\n");
    return notify_fail("你祭"+fabaoname+"失败。\n");
  }

  message_vision ("\n$N忽地抛起"+fabaoname+"，口中念念有词。\n",me,victim);
  
  message_vision ("刹那间"+fabaoname+"在空中一晃，卷起一股白雾。\n",me,victim);
  
  condition=determine_success(me, victim);

  switch(condition)
  {
      case 1:
             message_vision ("$n手中的"+ob->name()+"把持不定！\n",me,victim);
             message_vision ("说时迟那时快，"+ob->name()+"已被"+fabaoname+"收去！\n",me,victim);
             ob->unequip();
             if (ob->query_weight()>fabao->query_max_encumbrance())
             {
             	message_vision (ob->name()+"在"+fabaoname+"里化作一股烟散了！\n",me,victim);
                destruct(ob);
             }
             else ob->move(fabao);
	     
	break;
      case -1:
             message_vision ("$n一纵身，绕开了空中的"+fabaoname+"。\n",me,victim);
  }
  me->add("mana", -determine_cost("mana", 250));
  me->add("sen", -determine_cost("sen", 50));
  me->start_busy(random(3)+1);
  victim->kill_ob(me);
  if (interactive(me))
    fabao->add("interactive_usage",1);
  return 1;
}

int ji (string target)
{
  object fabao = this_object ();
  object me = this_player();
  string fabaoname = fabao->query("name");
  object victim;

  if (!target)
    return notify_fail("你想对谁祭"+fabaoname+"？\n");

  victim=present(target,environment(me));
  fabao->ji_ob(victim);
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

    if (attackfactor>dp/2) condition=1;
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
