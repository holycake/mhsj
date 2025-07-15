//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name("麻将牌", ({"majiang pai", "pai"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一副麻将牌。\n");
                set("unit", "副");
               set("owner_name","白晶晶");
               set("owner_id","bai jingjing");
        }
}
