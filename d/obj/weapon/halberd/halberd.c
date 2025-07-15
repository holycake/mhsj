// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit SPEAR;

void create()
{
        set_name("钢戟", ({ "ji", "halberd" })
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆平常的钢戟，打造得还不错。\n");
                set("value", 1000);
                set("material", "blacksteel");


         set("wield_msg", 
"寒光一现，只见$N手上闪出一把雪亮的$n。　\n") ;   
 set("unwield_msg", "$N放下手中的$n。\n");


 

        }
      init_spear(15);
        setup();
}

