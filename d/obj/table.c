//Cracked by Roath
#include <ansi.h>
#define LAST_PAR "bc"
#define THIS_PAR "bcsf"
inherit ITEM;
void create()
{
    set_name(HIW"大话西游补偿台"NOR, ({ "table"}));
    set_weight(5000000);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "个");
        set("no_get","这个台子是大话西游给玩家发礼物的，你不能偷走");
        set("long","一个巨大无比的礼物台，上面放满了发给大家的礼物，趁着没去掉大家快拿礼物(pick gift)啊！");
        set("value", 0);
        set("material", "stone");
    }
}
void init()
{
    add_action("do_pick", "pick");
}
 
int do_pick(string arg)
{
       object me,obj;
       me = this_player();
       if( !arg || arg!="gift" ) return notify_fail("你要拿什么？\n");

 //      return notify_fail("现在没有礼物拿。\n");

       if (me->query(THIS_PAR + "_pick")) {
       tell_object(me,CYN "麦克小狼的身影突然出现在一阵烟雾之中。\n\n");
       tell_object(me,HIR "麦克小狼一巴掌敲在你手上：小朋友，不要太贪心哦！每人只有一份礼物！\n\n");
       tell_object(me,CYN "只见一阵烟雾过後，麦克小狼的身影已经不见了。\n" NOR);
       return 1;
       }
      obj = new (__DIR__"gift");
      obj->move(me);
       message_vision("$N从礼物台上拿了一个礼物包。\n",me );
//每次拣礼物，都将上次的参数消除，增加本次拿的参数。 
       me->delete(LAST_PAR + "_pick");
       me->set(THIS_PAR + "_pick",1);
       return 1;
}

