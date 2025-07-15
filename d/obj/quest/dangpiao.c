//By waiwai@mszj 2000/12/02

inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
        set_name("当票", ({"dang piao","piao"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "这是董记当铺的专用票据。\n");
                set("unit", "张");
               set("owner_name","董朴升");
               set("owner_id","dong pusheng");
        }
}
