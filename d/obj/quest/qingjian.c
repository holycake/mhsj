
inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
        set_name("请柬", ({"qing jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是喜福会的专用请柬。\n");
                set("unit", "张");
               set("owner_name","老害虫");
               set("owner_id","xifuhui boss");
        }
}
