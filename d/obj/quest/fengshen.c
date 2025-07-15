//By waiwai@mszj 2000/12/02
inherit ITEM;
#include <ansi.h>
#include "task.h"
void create()
{
        set_name("封神榜", ({"fengshen bang", "bang"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一卷神榜,听说是用来封神用的。\n");
                set("unit", "卷");
               set("owner_name","太白金星");
               set("owner_id","tai bai");
        }
}
