//created by gslxz
//2001.9
#include <ansi.h>

inherit ITEM;
int do_open(string arg);
void create()
{
  set_name(HIR "礼物" NOR,({"gift"}));
  set("long","这是一份礼物，你可以试着打开("+HIR+"open"+NOR+")来看看。");
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
  if (!arg && arg!="liwu") return notify_fail("你要打开什么?\n");
  if (me->query("newbie_liwu")) return notify_fail("你已经拿过礼物了，怎么还想要？\n");
  message_vision(HIR"$N小心的将这个礼包打开，只听一个晴天霹雳，$N被一股蓝光罩住，$N大喊一声:魔幻世纪!赐予我力量吧!\n" NOR,me);
  
  me->add("potential",25000);  //the reward just is a example ,you can modify it as your wish. :P
  me->add("combat_exp",18000);
  me->set("max_kee",500);
  me->set("max_sen",500);
  me->set("eff_kee",500);
  me->set("eff_sen",500);
  me->set("kee",500);
  me->set("sen",500);
  me->set("maximum_force",600);
  me->set("maximum_mana",600);
  me->set("max_mana",600);
  me->set("max_force",600);
  me->set("mana",600);
  me->set("force",600);
 me->add("daoxing",20000);
this_player()->set_skill("force",60);
this_player()->set_skill("unarmed",60);
this_player()->set_skill("fork",60);
this_player()->set_skill("spear",60);
this_player()->set_skill("whip",60);
this_player()->set_skill("axe",60);
this_player()->set_skill("hammer",60);
this_player()->set_skill("mace",60);
this_player()->set_skill("throwing",60);
this_player()->set_skill("blade",60);
this_player()->set_skill("sword",60);
this_player()->set_skill("staff",60);
this_player()->set_skill("stick",60);
this_player()->set_skill("spells",60);
this_player()->set_skill("parry",60);
this_player()->set_skill("dodge",60);
this_player()->set_skill("rake",60);
this_player()->set_skill("literate",60);
//gslxz 9/16/2001
tell_object(me,HIG"你得到了：\n" +
  chinese_number(32000) + "点武学\n"+        
 chinese_number(50000) + "点潜能\n"+
  chinese_number(500)   + "点气血\n"+
  chinese_number(500)   + "点精神\n"+
  chinese_number(900)   + "点法力\n"+
  chinese_number(900)   + "点内力\n"+
  chinese_number(60)   + "级基本技能\n"+
chinese_number(100)    + "年道行\n" NOR);
  me->set("newbie_liwu",1);
  destruct(this_object());
  return 1;

}
