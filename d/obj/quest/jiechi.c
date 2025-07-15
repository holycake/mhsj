//Cracked by Roath

// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
            set_name("戒尺", ({"jie chi", "ruler" , "chi" }));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                    set("long", "元先生教训学童用的东西。\n");
                    set("unit", "根");
                   set("owner_name","元先生");
                   set("owner_id","yuan xiansheng");
        }
}
