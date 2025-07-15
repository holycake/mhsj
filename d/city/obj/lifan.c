// gift.c
// by gslxz@mhsj 2001/9/23
#include <ansi.h>

inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "国庆节大礼包" NOR,({"gift","bao","bag"}));
  set("long","这是国庆节礼包，里面装满了好东东，你可以试着打开("+HIR+"open"+NOR+")来看看。");
  set("unit","份");
  set("value", 0);
  setup();
}

void init()
{
   if (!wizardp(this_player())) {
    set("no_get","这个东西拿不起来。\n");
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
     object ob = new("/obj/money/thousand-cash");
  if (!arg && arg!="gqgift") return notify_fail("你要打开什么?\n");
  if (me->query("newbie_gqgift")) return notify_fail("你已经拆过大礼包了，难道你不记得了吗？\n");
  if ((int)me->query("age")<16) return notify_fail("你的年龄还太小，还不能打开国庆节大礼包。:P\n");
  message_vision(HIC"$N小心的将"HIR"国庆节大礼包"HIC"打开，顿时天空中出现了一面国旗。\n" NOR

HIY"                                 国  庆  节  快  乐                                    \n"NOR
"\n"
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR 
"        "HBRED" "HIY"                ☆                                                      \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED" "HIY"        ★      ☆                                                      \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED" "HIY"              ☆                                                        \n"NOR
"        "HBRED" "HIY"         ☆                                                             \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR
"        "HBRED"                                                                         \n"NOR,me);

  
       ob->set_amount(52);
       ob->move(me);
  me->add("potential",52000);  
  me->add("combat_exp",52000);
 me->add("daoxing",52000);
  me->skill_death_recover();
// by gslxz@mhsj 2001/9/23
tell_object(me,HIG"为了庆祝国庆52周年，你得到了：\n" +
 chinese_number(52000) + "点武学\n"+        
 chinese_number(52000) + "点潜能\n"+
  chinese_number(52)    + "年道行\n"+
  chinese_number(52)    + "张一千两的银票\n"+
 "另外，你的所有技能各增加1级！\n"  NOR);
  me->set("newbie_gqgift",1);
  destruct(this_object());
  return 1;

}
