//By waiwai@mszj 2000/12/02

inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
        set_name("考题", ({"kaoti", "ti"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "贺知章出的考题。\n");
                set("unit", "份");
               set("owner_name","贺知章");
               set("owner_id","he zhizhang");
        }
}
