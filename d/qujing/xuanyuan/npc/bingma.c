// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

inherit ITEM;
#include <ansi.h>
void create ()
{
  set_name("人俑", ({ "ren yong", "yong" }) );
  set_weight(900000);
  if (clonep())
    set_default_object(__FILE__);
  else
  {
    set("long", "一尊栩栩如生的人俑。让人不禁想模仿（act）其动作。\n");
    set("unit","尊");
  }
  setup();
}

int init ()
{
  add_action ("do_act","act");
  return 1;
}

int do_act (string arg)
{
  string *msgs = ({
   HIR "$N对着人俑，拿针向它全身刺去。\n"NOR,
   HIR "$N一边看着人俑，一边发出一道寒星。\n"NOR,
  });
  string *actions = ({
   HIY "你感觉到自己的格斗术有了进步。\n"NOR,
   HIY "你的针法提高了。\n"NOR,
  });
  object me = this_player();
  object ren = this_object();

  if (arg != "ren yong" &&
      arg != "yong")
  {
    tell_object(me,"你想跟谁比划呢？\n");
    return 1;
  }
  if (me->query("kee")<10 ||
      me->query("sen")<10)
  {
    tell_object (me,"你已经太疲劳了！\n");
    //me->unconcious();
    return 1;
  }
  if (me->is_busy())
  {
    tell_object (me,"你正在忙着呢！\n");
    return 1;
  }
   if ((int)me->query_skill("unarmed", 1)< 150 || (int)me->query_skill("tianyi-zhen", 1)< 150)
      return notify_fail("你已经不需要在这种地方修行了.\n");
  if((string)me->query("family/family_name")!="轩辕古墓")
    return notify_fail("你不是我们轩辕古墓的，这么做不合适吧？\n");
  ren->add("times",1);
  message_vision (msgs[random(sizeof(msgs))],me);
  me->add("kee",-10);
  me->add("sen",-10);
  me->improve_skill("unarmed",random((int)me->query_skill("unarmed",1)/10),1);
  me->improve_skill("tianyi-zhen",random((int)me->query_skill("tianyi-zhen",1)/10),1);
  tell_object (me,actions[random(sizeof(actions))]);
  me->start_busy(1,1);
  if (ren->query("times")>100)
  {
    message_vision ("只见$N摇摇晃晃，轰地一下倒在地上碎了。\n",ren);
    destruct (ren);
  }
  return 1;
}
