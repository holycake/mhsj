
#include <weapon.h>
#include <ansi.h>


inherit SWORD;

void create()
{
   set_name( MAG "青锋细雨剑" NOR, ({ "qingfeng sword", "jian", "sword" }) );
   set_weight(8000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "把");
                set("no_give", 1);

                set("no_sell", 1);

                set("no_get", 1);

                set("no_put", 1);

                set("value", 0);


     set("material", "steel");
     set("long", "这是一把又细又长的剑，剑身锐利。\n");
     set("wield_msg", "一道青光闪过，$N手中已多了把$n。\n");
     set("unequip_msg", "$N放下手中的$n。\n");
   }
   init_sword(50);
   setup();
}
