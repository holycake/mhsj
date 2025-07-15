#include <ansi.h>

inherit ITEM;


void create()
{
          set_name(HIW"千年樱花树"NOR, ({ "tree","shu",  }) );
        set_weight(3000000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", HIM"一株千年樱花树，清风一吹，片片花瓣随风飘落。\n"NOR);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
  set("chat_chance", 5);
  set("chat_msg", ({
    "忽悠叹道：西瓜少爷，需要我为你捶背吗?\n",
    "忽悠说道：西瓜少爷，我做的可可豆出锅了，你要吃点吗?\n",
    "忽悠叹道：西瓜少爷，今天我做炉包，你吃吗?\n",
  }));
// object money = new ("/obj/money/gold");
 //add_money("gold", 1000);
  //      money->move(environment(me));
        setup();

}

