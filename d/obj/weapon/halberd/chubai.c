// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit F_UNIQUE;
inherit HALBERD;

void create()
{
        set_name("楮白枪", ({ "chubai qiang", "halberd" ,"ji"})
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "小张太子惯用之物，蠙城所传至宝，由海底寒铁铸成。\n");
                set("value", 20000);
     set("replace_file", "/d/obj/weapon/halberd/huaji");
                set("material", "blacksteel");
        }
        init_halberd(70);
        set("is_monitored",1);
        setup();
         set("wield_msg", 
"寒光一现，只见$N手上闪出一把雪亮的$n。　\n") ;   
 set("unwield_msg", "$N放下手中的$n。\n");

}

