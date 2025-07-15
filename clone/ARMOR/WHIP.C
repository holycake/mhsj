// blade.c

#include <weapon.h>
#include <ansi.h>

inherit WHIP;

void create()
{
     set_name(WHT "打神鞭" NOR, ({"whip"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
      set("long",WHT"此鞭乃姜子牙所用\n"NOR);
                set("unit", "条");
                 set("value", 30000);
        }
        init_whip(85);
        setup();
}

