//Cracked by Roath

inherit ITEM;
inherit F_LIQUID;

void create()
{
   set_name("[36m大海碗[m", ({"haiwan", "wan"}));
   set_weight(700);
   if (clonep())
     set_default_object(__FILE__);
   else {
     set("long", "一个精美的大碗。\n");
     set("unit", "个");
     set("value", 100);
     set("max_liquid", 30);
   }
   set("liquid", ([
     "type": "water",
     "name": "红茶",
     "remaining": 10,
     "drunk_supply": 10,
   ]));
}
