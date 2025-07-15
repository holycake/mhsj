//created by vikee
//2000.10

#include <ansi.h>
inherit ITEM;

int get_liwu(string arg);
void create()
{
  set_name(HIR"国庆节"HIY"礼物台" NOR ,({"gift table","table"}));
  set("long","这是魔幻世纪开发组为了庆祝国庆52周年纪念，奖励各位玩家而做的礼物台，\n"
 "玩家可以在这里拿("HIR"take"NOR")礼物("HIR"gift"NOR")。");
  set("unit", "个");
  set("value", 1000000000000);
}

void init()
{
  if (!wizardp(this_player())) 
    set("no_get","这个东西拿不起来。\n");
  add_action("get_gift","take");
}

int get_gift(string arg)
{
  object me = this_player();
  object lw;
  if (arg!="gift")      return 0;
  if (me->query("newbie_gift")) return notify_fail("你已经拿过礼物了,别太贪心哟！\n");
   if ((int)me->query("age")<16) return notify_fail(HIR"小朋友你的年龄还太小，还不能领取国庆节大礼包。:P\n"NOR);
 message_vision("$N从礼物台上拿下一份礼物。\n" NOR, me);
  lw=new("/d/city/obj/giftt");  //the directory you can modify it yourself.:P added by vikee 10/5/2000
  lw->move(me);
  me->set("newbie_gift",1);
  return 1;
}
