// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */

#include <weapon.h>

inherit HALBERD;

void create()
{
        set_name("方天画戟", ({ "fangtian huaji", "huaji", "halberd","ji" })
);
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "杆");
                set("long", "一杆沉重的方天画戟，锋利无比，最适合在战场上使用。\n");
                set("value", 1000);
                  set("material", "blacksteel");
        }
         init_halberd(35);
        setup();
}

