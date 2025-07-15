#include <ansi.h>

inherit ITEM;

int do_eat(string);
void create()
{
  set_name(HIC "碧水丹" NOR, ({"bishui dan", "dan"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "颗");
    set("long", "碧油油的一颗碧水丹。\n");
    set("value", 5000);
    set("no_sell", 1);
  }
  
  setup();
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
  object me = this_player();
    
  if (!id(arg))
    return notify_fail("你要吃什么？\n");

	message_vision(HIC"$N吃下一颗碧水丹，脸色变的一片惨白。\n"NOR, me);  
        if (me->query("cool_dan") >= 100)
        {
        } else
        if (random(100) == 0)
        {
        } else
        {
	me->add("bellicosity", -random( (int)me->query_kar() * 10));
	if ((int)me->query("bellicosity") < 0 ) me->set("bellicosity", 0);
	me->add("potential", 100);

        }
        if (me->query("qianneng") >= 500)
	me->set("potential", 0);
	me->add("daoxing", -10000);
               tell_object(me, HIR"系统怀疑你作弊，吃下了500颗碧水丹，你将受到减少道行和潜能的处罚。\n"NOR);
               tell_object(me, HIR"系统将你的潜能值改为0，你的道行掉了10年。\n"NOR);

        me->add("cool_dan", 1);
              me->add("qianneng", 1);
        destruct(this_object());
  
  destruct(this_object());
  return 1;
}
