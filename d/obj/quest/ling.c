//魔幻世纪 gslxz

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name(HIR"追杀令"NOR, ({"zhuisha ling", "ling"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一个红色的追杀令。\n");
                set("unit", "个");
               set("owner_name","花忍");
               set("owner_id","hua ren");
        }
}
