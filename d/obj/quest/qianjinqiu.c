inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
        set_name("千金裘", ({"qianjin qiu", "qiu"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "李白用来换酒喝的，象征名贵的衣服。\n");
                set("unit", "件");
               set("owner_name","李白");
               set("owner_id","li bai");
        }
}


