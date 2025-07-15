//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name("火尖枪", ({"huojian qiang", "qiang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一杆火焰火尖枪,威力无比。\n");
                set("unit", "杆");
               set("owner_name","哪 吒");
               set("owner_id","nezha santaizi");
        }
}
