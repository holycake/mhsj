//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name("挑战书", ({"tiaozhan shu", "shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一张挑战书。\n");
                set("unit", "张");
               set("owner_name","范青屏");
               set("owner_id","fan qingping");
        }
}
