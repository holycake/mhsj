//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include "task.h"
void create()
{
        set_name("勺子", ({"shao zi"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把钢制的做饭用的勺子。\n");
                set("unit", "把");
               set("owner_name","掌厨僧");
                set("owner_id","zhangchu seng");
        }
}

