//By gslxz@魔幻世纪 2001/6/08

inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
        set_name("人参果", ({"renshen guo", "guo"}));
        set_weight(30);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "白白胖胖的一枚人参果。三千年一开花，三千年一结果，再三千年才得熟，实是天地间的灵宝。\n");
                set("unit", "个");
               set("owner_name","镇元大仙");
               set("owner_id","zhenyuan daxian");
        }
}


