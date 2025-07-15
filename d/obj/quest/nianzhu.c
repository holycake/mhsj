//Cracked by Roath

// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
                set_name("念珠", ({"nian zhu" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                        set("long", "布金禅寺方丈用的念珠。\n");
                        set("unit", "串");
                     set("owner_name","方丈");
                     set("owner_id","fang zhang");
        }
}
