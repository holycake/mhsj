//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include "task.h"
void create()
{
        set_name("剃刀", ({"ti dao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把专门用来超度出家人的剃刀。\n");
                set("unit", "把");
               set("owner_name","剃度僧");
                set("owner_id","tidu seng");
        }
}

