//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
        set_name("珍珠", ({"tan zhu", "zhu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一颗闪闪发亮的珍珠。\n");
                set("unit", "颗");
           }
}
