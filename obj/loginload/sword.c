// by mhsj@gslxz 2001/3/12

#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
          set_name(WHT "雪色神剑" NOR, ({"sword", "jian"}));
        set_weight(10000);
                set("unit", "把");
        if( clonep() )
                set_default_object(__FILE__);
        else {
                  set("long","这是一把看起相当普通的长剑，但它的用途往往却出人意料。\n");
      set("value", 0);
                set("weapon_prop/courage", 10);
        }
        init_sword(20);
        setup();
}