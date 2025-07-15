// table.c
// by gslxz@mhsj 2001/9/23
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
  set_name(HIR"国庆节"HIY"礼物台" NOR ,({"gift table","table"}));
  set("long","这是魔幻世纪开发组为了庆祝国庆52周年纪念，奖励各位玩家而做的礼物台，\n"
 "玩家可以在这里拿("HIR"take"NOR")礼物("HIR"gift"NOR")。");
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("no_get","这里人太多了，你没发下手。");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_take", "take");
}
 
int do_take(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("你要拿什么？\n");

 //      return notify_fail("现在没有礼物拿。\n");
// by gslxz@mhsj 2001/9/23

  if ((int)me->query("age")<16) return notify_fail("你的年龄还太小，还不能打开国庆节大礼包。:P\n");
       if (me->query(THIS_PAR + "_take")) {
       tell_object(me,CYN "西瓜太郎的身影突然出现在一阵烟雾之中。\n\n");
       tell_object(me,HIR "西瓜太郎一巴掌敲在你手上：小朋友，不要太贪心哦！每人只有一份礼物！\n\n");
       tell_object(me,CYN "只见一阵烟雾过後，西瓜太郎的身影已经不见了。\n" NOR);
       return 1;
       }
      obj = new (__DIR__"giftt");
      obj->move(me);
       message_vision("$N从"HIR"国庆节"HIY"礼物台"NOR"上拿了一个"HIR"大礼包。\n"NOR,me );
//每次拣礼物，都将上次的参数消除，增加本次拿的参数。 
       me->delete(LAST_PAR + "_take");
       me->set(THIS_PAR + "_take",1);
       return 1;
}

