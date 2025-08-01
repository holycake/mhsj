// by gslxz@mhsj 2001/11/21 (优化)
#include <ansi.h>
inherit NPC;

void create()
{
  set_name("灵宝道君", ({"lingbao daojun", "lingbao", "daojun"}));
  set_weight(75000);
  set("long", "一尊丈许高的灵宝道君的泥塑圣象，在殿台上正颜端坐。\n");
  set("unit", "尊");
  set("title", "圣象");
  set("value", 10000);
  set("age", 100);
  set("max_gin", 10);
  set("max_kee", 10);
  set("max_sen", 10);
  set("no_get","这圣象如此之重，不用力去搬恐怕分寸难移也。\n");
  set("no_drop","你将圣象往地上一放，又觉不妥，硬着头皮又搬了起来。\n");
  set("no_give","圣象如此之大，怕是给不了人吧。\n");
  set("no_sell","圣象非卖品也。\n");
  setup();
}

void init ()
{
  add_action ("do_get","get");
  add_action ("do_lift","lift");
  add_action ("do_throw","throw");
}

int do_get (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return 0;
  obj = present(arg,where);
  if (obj == who)
    obj = present(arg+" 2",where);
  if (obj == me)
  {
    tell_object(who,"恐怕要花吃奶的力气去搬才能搬得动吧。\n");
    return 1;
  }
  return 0;
}

int do_lift (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return notify_fail("你要搬什么？\n");
  obj = present(arg,where);
  if (obj == who)
    obj = present(arg+" 2",where);
  if (! obj)
    return notify_fail("你要搬什么？\n");
  if (obj != me)
    return notify_fail("你要搬什么？\n");
  if (where->query("short") != "三清殿")
  {
    message_vision("$N使了吃奶的力气也没能将圣象搬起来。\n",who,me);
    return 1;
  }
  me->move(who);
  if (environment(me) != who)
  {    
    message_vision("$N憋红了脸一使劲，$n只是晃了一晃。\n",who,me);
    return 1;
  }
  message_vision ("$N大喝一声，稳稳地将$n扛在肩上。\n",who,me);
  return 1;
}

int do_throw (string arg)
{
  object me = this_object();
  object who = this_player();
  object where = environment(who);
  object obj;

  if (! arg)
    return notify_fail("你要扔什么？\n");
  obj = present(arg,who);
  if (! obj)
    return notify_fail("你要扔什么？\n");
  if (obj != me)
    return notify_fail("你要扔什么？\n");
  if (where->query("short") != "五谷轮回")
    return notify_fail("这里怕是没有扔圣象的地方。\n");
  if (environment(me) != who)
    return notify_fail("这里怕是没有扔圣象的地方。\n");

  message_vision ("$N将$n举过头顶，往坑里一扔。\n",who,me);
  remove_call_out ("destruct_me");
  call_out ("destruct_me",1,who,me);
  return 1;
}

void destruct_me (object who, object me)
{
  message_vision ("只听“嗵”地一声，$n溅起一阵臭气。\n",who,me);
  destruct (me);
}

void die ()
{
  this_object()->remove_all_killer();
  all_inventory(environment())->remove_killer(this_object());

  set("gin", 10);
  set("kee", 10);
  set("sen", 10);
  revive();
  reincarnate();
}

void unconcious ()
{
  die();
}

