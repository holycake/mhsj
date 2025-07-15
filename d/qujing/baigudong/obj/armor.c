//modified from pingding/obj/armor by smile 12/10/1998
#include <armor.h>

inherit ARMOR;

string *prefixs = ({
  "人",
  "虎",
  "狮",
   "豹",
   "熊",
   "狼",
});

string *names = ({
  "骨甲",
  "皮甲",
});

void create()
{
  set_name(prefixs[random(sizeof(prefixs))]+names[random(sizeof(names))],
           ({"armor","jia"}));
  set_weight(10000+random(5000));
  if ( clonep() )
     set_default_object(__FILE__);
  else {
   set("unit", "件");
   set("value", 500);
   set("material", "shell");
   set("armor_prop/armor", 20+random(20));
  }
   set("no_sell",1);
  setup();
}
