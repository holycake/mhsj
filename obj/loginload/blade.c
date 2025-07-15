// by mhsj@gslxz 2001/3/12
#include <weapon.h>
#include <ansi.h>;

inherit BLADE;

void create()
{
        set_name(RED"嗜血魔刀"NOR, ({"blade","dao"}));
          set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
             set("long", "这是一把看起相当诡异的刀，但它的用途往往却出人意料。\n");
        set("value", 0);
                set("material", "gold");
        set("weapon_prop/courage", 15);

        }
        init_blade(20);
        setup();
}