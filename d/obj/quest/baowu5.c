//Cracked by Roath
// 神话世界・西游记・版本４．５０
/* <SecCrypt CPL V3R05> */
inherit ITEM;
#include "task.h"
void create()
{
        set_name("金蛟剪", ({"jinjiao jian","jian"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "此剪乃是两条蛟龙，采天地灵气，受日月精华，起在空中，往来上下，\n祥云护体，头并头如剪，尾交尾如股；不怕你得道神仙，一插两段。\n");
                set("unit", "件");
                set("lingtaibao","fake");
                 set("owner_name","菩提祖师");
                 set("owner_id","master puti");
        }
}

