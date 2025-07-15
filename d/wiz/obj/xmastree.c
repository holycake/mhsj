#include <ansi.h>

inherit ITEM;

void create()
{
    set_name(HIW"圣诞树"NOR, ({ "shengdan shu","xmas tree","tree"}));
    set_weight(5000000);
    set("unit", "棵");
    set("long", "一棵布置精美的圣诞树，上面挂满了精美的圣诞卡(card),\n"
         +"让人禁不住想拿(pick)下来.\n");
    set("no_get","这么重的圣诞树你也想搬走？\n");
    set("value", 0);
}

void init()
{
    add_action("do_pick", "pick");
}

int do_pick(string arg)
{
       object me,ob;
       me = this_player();
       if (!arg || arg!="card" ) return notify_fail("你要拿什么？\n");

	if (me->query("yudian/card")=="got")
	{
  switch (random(1))
         {
	case 0:
         {message_vision("$N轰地从树上跌下来，摔了个大屁蹲！\n",me );break;}
	case 1:
         {message_vision("$N张牙舞爪地什么也没抓着！\n",me );break;}
	}
	return 1;
           }

  switch (random(2))
  {
    case 0:
          { message_vision("$N蹭蹭几下就爬到了树尖，潇洒地拿了张圣诞卡冲着树下众人频频挥手！\n",me );break;}
       case 1:
          { message_vision("$N张牙舞爪地抓了一张圣诞卡片！\n",me );break;}
       case 2:
       {message_vision("$N终于抓着一张精美的圣诞卡，累得一身大汗！\n",me );break;}
}
	me->set("yudian/card","got");
       ob=new("/d/wiz/obj/card.c");
       ob->move(me);
	ob->set("owner",me->query("id"));
       return 1;
}

