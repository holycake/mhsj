//By gslxz@mhsj 2001/6/08

inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
        set_name("肉骨头", ({"rou gutou","gutou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是一块很普通的肉骨头。\n");
                set("unit", "块");
               set("owner_name","野狗");
               set("owner_id","dog");
        }
}
