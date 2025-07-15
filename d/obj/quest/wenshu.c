//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
        set_name("文书", ({"wen shu", "shu"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "寂灭司主「阴王」阴长生的文书。\n");
                set("unit", "件");
               set("owner_name","阴长生");
               set("owner_id","yin changsheng");
        }
}
