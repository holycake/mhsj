//by mhsj@gslxz /2001/7/26
// literate.c
#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(WHT"〖论语〗"NOR, ({"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 1000);
        set("material", "paper");
        set("skill", ([
                        "name": "literate",
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 120,
]) );
        }
}

