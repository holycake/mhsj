#include <ansi.h>
inherit ITEM;
string *list=({"/clone/datao","/clone/mhtao","/clone/liwan",
	"/clone/xisui","/clone/perda","/clone/linen","/obj/money/coin","/obj/money/silver","/obj/money/gold","/obj/money/thousand-cash",
	"/clone/xieyao","/clone/pigu","/clone/pidudan","/clone/piduzhu"});
int do_open(string arg);
void create()
{
  set_name(HIY"月光宝盒" NOR,({"bao he"}));
  set("long","这是一份礼物，你可以试着打开("+HIR+"open"+NOR+")来看看。");
  set("unit","份");
  set("value", 0);
  setup(); 
}
 
void init()
{
   if (!wizardp(this_player())) {
    set("no_give","这么珍贵的东西，哪能随便给人？\n");
    set("no_drop","这么宝贵的东西，扔了多可惜呀！\n");
    set("no_sell","这东西不能卖。\n");
   }
  if(this_player()==environment())
  add_action("do_open", "open");
}

int do_open(string arg)
{
  object me=this_player();
  object liwu;
  if (!arg && arg!="baohe") return notify_fail("你要打开什么?\n");
  message_vision(CYN"“啪”的一声不知道什么东西掉到了$N的怀里!\n" NOR,me);
  liwu = new(list[random(sizeof(list))]);
  liwu->move(me);
  destruct(this_object());
  return 1;
}
