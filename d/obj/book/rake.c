//by mhsj@gslxz /2001/7/26
// rake.c
#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(WHT"〖基本钯法〗"NOR, ({"rake book", "book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "本");
		set("value", 1000);
        	set("no_drop", 1);
        	set("no_get", 1);
        	set("no_sell", 1);
        set("material", "paper");
        set("skill", ([
                        "name": "rake",
                        "exp_required": 100,
                        "sen_cost": 20,
                        "difficulty": 20,
                        "max_skill": 120,
]) );
        }
}

