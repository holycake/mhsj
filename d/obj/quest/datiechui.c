//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name(YEL "大号铁锤" NOR, ({"datie chui", "chui"}));
        set_weight(50);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一把打铁用的锤子。\n");
                set("unit", "碗");
               set("owner_name",HIR"张铁臂"NOR);
               set("owner_id","Blacksmith");
        }
}


