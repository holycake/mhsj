//Cracked by Roath

// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
#include <ansi.h>
void create()
{
                  set_name(HIG "玉玲珑" NOR, ({"yu linglong" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                          set("long", "探春最心爱的饰物。\n");
                      set("unit", "个");
                       set("owner_name","探春");
                       set("owner_id","tan chun");
        }
}
