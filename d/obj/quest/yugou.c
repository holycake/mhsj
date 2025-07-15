//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include "task.h"

void create()
{
        set_name("鱼钩", ({"yu gou"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", " 渔夫张梢心爱之物。\n");
                set("unit", "个");
               set("owner_name","张梢");
               set("owner_id","fisher");
        }
}
