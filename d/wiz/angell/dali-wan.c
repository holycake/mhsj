#include <ansi.h>

inherit ITEM;

int do_eat(string);

void init();

void init()

{

if (!wizardp(this_player())) {

//   set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");

set("no_give","这么珍贵的药，哪能随便给人？\n");

set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");

set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");

} 

add_action("do_eat", "eat");

}

void create()

{

set_name(HIC "大力丸" NOR, ({"dali wan","daliwan","wan"}));

set_weight(20);

if (clonep())

set_default_object(__FILE__);

else {

set("unit", "颗");

set("long", "亮晶晶的一颗大力丸，听说吃了可以.....嘿嘿! \n");

set("value", 5000);

set("drug_type", "补品");

}

setup();

}

int do_eat(string arg)

{

object me = this_player();

if (!id(arg))

return notify_fail("你要吃什么？\n");

me->set("food", (int)me->max_food_capacity());

me->add_maximum_force(100);

me->add_maximum_mana(100);

me->add("potential", 784);

me->add("combat_exp", 867);

me->add("daoxing", 8532);

message_vision(HIR "$N吃下一颗大力丸，迷迷糊糊的不知道在干什么了！ \n" NOR, me);

destruct(this_object());

return 1;

}

