//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <armor.h>

inherit CLOTH;

void create()
{
        set_name("[1;31m五[32m彩[35m织[33m金[37m袈[36m裟[m", ({"wucai jiasha", "jia sha"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
     set("long", "此乃唐王所赐之袈裟．\n");
                set("material", "cloth");
                set("no_drop",1);
                set("no_sell",1);
//                  set("value", 300);
                  set("value", 20000000);
                set("unit", "件");
                set("armor_prop/armor", 10);
        }
        setup();
}

int query_autoload() { return 1; }
