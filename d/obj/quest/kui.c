//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
        set_name("紫金盔", ({"zijin kui", "kui"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "当年薛仁贵征战沙场所戴的宝盔。\n");
                set("unit", "顶");
               set("owner_name","薛仁贵");
               set("owner_id","xue rengui");
        }
}


