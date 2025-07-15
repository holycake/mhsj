//By waiwai@mszj 2000/12/02

#include <ansi.h>

inherit ITEM;
#include "task.h"
void create()
{
        set_name(YEL"道德经"NOR, ({"daode book", "book"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "法明的书本。\n");
                set("unit", "本");
               set("owner_name","法明长老");
               set("owner_id","faming zhanglao");
        }
}
