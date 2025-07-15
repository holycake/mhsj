
inherit ITEM;
#include "task.h"
#include <ansi.h>

void create()
{
        set_name("墨镜", ({"mo jing"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一副鼹鼠的专用墨镜。\n");
                set("unit", "副");
               set("owner_name","鼹鼠");
                set("owner_id","yan shu");
        }
}

