//By gslxz@mhsj 2001/6/08

#include <ansi.h>

inherit ITEM;
#include "task.h"
void create()
{
        set_name("凤凰琴", ({"fenghuang sword", "fenghuang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一尊玉雕刻成的凤凰琴。\n");
                set("unit", "把");
                   set("owner_name",HIG"孔雀公主"NOR);
                set("owner_id","kongque gongzhu");
        }
}

