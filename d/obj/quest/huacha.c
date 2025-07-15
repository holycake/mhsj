//By waiwai@mszj 2000/12/02

inherit ITEM;

#include <ansi.h>
#include "task.h"

void create()
{
        set_name("花茶", ({"hua cha", "cha"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "一包花茶。\n");
                set("unit", "包");
               set("owner_name","茶娘子");
               set("owner_id","chaniang zi");
        }
}
