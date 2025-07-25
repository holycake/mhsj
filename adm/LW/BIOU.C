//碧藕


#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_get","你手里一松"+this_object()->query("name")+"丹从指间滑落！\n");
    set("no_give","这么珍贵的药，哪能随便给人？\n");
    set("no_drop","这么宝贵的丹药，扔了多可惜呀！\n");
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
    add_action("do_eat", "eat");
}

void create()
{
  set_name(HIW "碧藕" NOR, ({"bi ou","ou"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "枚");
    set("long", "一枚采自海中仙山，浑然如玉的碧藕。\n");
    set("value", 5000);
	set("drug_type", "补品");
  }
  
  // the following line is added by snowcat
  set("is_monitored",1);
  setup();
}

int do_eat(string arg)
{
  object me = this_player();
  int force_add, howold;
  howold = (int)me->query("mud_age") + (int)me->query("age_modify");
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
  me->set("food", (int)me->max_food_capacity());
  me->set("water", (int)me->max_water_capacity());
  force_add = 2+random(2);
  me->add("eat_biou", 1);
  if ( (int)me->query("eat_biou") > 10) {
    if( (int)me->query("maximum_force") > 100 ) {
      me->add_maximum_force(-5);
    }
    me->delete("eat_biou");
    message_vision(HIG "$N吃下一枚碧藕，脸色突然转绿，「哇哇」几口又吐了出来！\n" NOR, me);
    tell_object(me,BLK "你口中又苦又涩，原来是枚苦藕！\n" NOR);
  }
  else if( me->add_maximum_force(force_add)) {
    message_vision(HIG "$N吃下一枚碧藕，脸色变的如同良玉一般雪白！\n" NOR, me);
  }
  else message_vision(HIG "$N吃下一枚碧藕，脸色突然发青，过了许久才转为平常！\n" NOR, me);
  
  if( howold > 1382400 ) {
    me->add("age_modify", -1200);
    me->add("age_modify_time", 1);
  }
  destruct(this_object());
  return 1;
}

