//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
                set_name("风口袋", ({"feng kou dai" , "koudai" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                        set("long", "风婆婆装风用的大口袋。\n");
                      set("unit", "个");
                       set("owner_name","风婆");
                     set("owner_id","feng po");
        }
}
