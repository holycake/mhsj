// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit F_UNIQUE;
inherit HALBER;

void create()
{
        set_name("兽骨戟", ({ "chubai qiang", "halberd" ,"ji"})
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆白森森的上古神兵。\n");
                set("value", 20000);
     set("replace_file", "/d/obj/weapon/halberd/huaji");
                set("material", "blacksteel");
        }
        init_halberd(80);
        set("is_monitored",1);
        setup();
}

