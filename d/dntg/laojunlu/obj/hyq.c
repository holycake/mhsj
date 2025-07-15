//hyq.c @waiwai  2000/07/10

#include <ansi.h>

#include <weapon.h>

inherit SPEAR;

void create()
{
   set_name(HIB"长柄"+HIR"红樱枪"NOR, ({ "hyq","qiang","spear" }) );
   set_weight(5000);
   if( clonep() )
     set_default_object(__FILE__);
   else {
     set("unit", "杆");
     set("value", 0);
     set("no_give", 1);
     set("no_sell", 1);
     set("no_get", 1);
     set("no_put", 1);

     set("material", "wood");
     set("long", "一杆长枪。\n");
     set("wield_msg", "$N抄起一杆$n，顺手抖了个枪花。\n");
     set("unwield_msg", "$N哼了一声，将$n反手顺于背后。\n");
   }
   init_spear(50);
   setup();
}
