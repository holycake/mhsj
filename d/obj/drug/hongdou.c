// hongdou.c 红豆
// create by cnd
#include <ansi.h>

inherit ITEM;

int do_kiss(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"从指间滑落！\n");
    set("no_give","这么珍贵的豆子，哪能随便给人？\n");
    set("no_drop","这么心爱的东西，扔了多可惜呀！\n");
    set("no_sell","无情之人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_kiss", "kiss");
}

void create()
{
  set_name(HIR "红豆" NOR, ({"hong dou","hongdou","dou"}));
  set_weight(20);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "一粒生于南国的相思豆，是情人最最珍爱的情物,你不禁想亲吻一下。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }
  
  setup();
}

int do_kiss(string arg)
{
  object me = this_player();
  
  if (!id(arg))
    return notify_fail("你要亲吻什么？\n");
  
  me->add_maximum_force(10);
  me->add_maximum_mana(10);
  message_vision(HIR "$N亲了一下相思红豆，相思红豆发出耀眼光芒，$N不禁缠绵起来！ \n" NOR, me);
  
  destruct(this_object());
  return 1;
}
