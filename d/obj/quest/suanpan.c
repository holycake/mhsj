//By waiwai@mszj 2000/12/02

inherit ITEM;
#include "task.h"
#include <ansi.h>

void create()
{
        set_name("算盘", ({"suan pan", "pan"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "铁算盘用的算账算盘。\n");
                set("unit", "个");
               set("owner_name","铁算盘");
               set("owner_id","tie suanpan");
        }
}
