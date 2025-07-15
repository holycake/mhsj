// gangcha.c
#include <ansi.h>

#include <weapon.h>

inherit FORK;

void create()
{
       set_name(HIW"龙筋虎骨叉"NOR, ({ "longhu fork", "cha"}) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
             set("value", 20000);
                set("material", "iron");
    set("long", HIW"这是由龙筋虎骨制作而成的叉子。\n"NOR);
                set("wield_msg", "$N抄起一柄$n轻轻的握在手里。\n");
        }
   init_fork(120);
        setup();
}

