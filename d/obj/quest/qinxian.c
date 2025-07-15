//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name("琴弦", ({"qin xian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一根琴弦。\n");
                set("unit", "根");
               set("owner_name",HIY"春十三娘"NOR);
               set("owner_id","chun shisanniang");
        }
}
