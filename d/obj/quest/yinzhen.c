//By waiwai@mszj 2000/12/02

inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
        set_name("银针", ({"yin zhen", "zhen"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "针灸用的银针。\n");
                set("unit", "顶");
               set("owner_name","雾渊道长");
               set("owner_id","wuyuan daozhang");
        }
}


