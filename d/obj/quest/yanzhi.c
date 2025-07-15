//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>

#include "task.h"
void create()
{
        set_name("胭脂", ({"yan zhi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "白晶晶的专用化妆用品。\n");
                set("unit", "盒");
               set("owner_name","白晶晶");
               set("owner_id","bai jingjing");
        }
}

