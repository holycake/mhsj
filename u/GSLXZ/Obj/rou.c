// rou.c 	取经人肉

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
  if (!wizardp(this_player())) {
    set("no_sell","凡人哪里知道"+this_object()->query("name")+"的价值？还是自己留着吧。\n");
  }                                    
  add_action("do_eat", "eat");
}

void create()
{
  set_name(YEL "取经人肉" NOR, ({"qujingren rou","renrou","rou"}));
  set_weight(50);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "块");
    set("long", "天下的至宝,吃了可以长生不老,还可以增加法术。\n");
    set("value", 5000);
    set("drug_type", "补品");
  }

  set("is_monitored",1);  
  setup();
}

int do_eat(string arg)
{
	int howmany;
  object who = this_player();
  
  if (!id(arg))
    return notify_fail("你要吃什么？\n");
  
	howmany = (int)who->query("renrou_eaten");
  
	who->set("food", (int)who->max_food_capacity());

		if( howmany <= 100 ) who->add_maximum_force(20);
		if( howmany <= 100 ) who->add_maximum_mana(20);

	who->set("renrou_eaten", howmany+1);

	message_vision("$N将一块"+this_object()->query("name")+"吃了下去。\n" NOR, who);  
//  who->delete("no_qujing");
         if( who->query("renrou_eaten") >= 81 )
        {
                who->announce_live_forever( who->query("name")+"吃满九，九，八十一块取经人肉终于修成了不堕轮回，从此跳出三界外，不在五行中，永无生死大限了！" );
        }
 if (!wizardp(who))
 destruct(this_object());
  return 1;
}

