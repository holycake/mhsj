// by gslxz@mhsj 2001/10/17
#include <weapon.h>
#include <ansi.h>

inherit RAKE;

void create()
{
          set_name(WHT "钉钯" NOR, ({ "dingpa","rake","pa" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "个");
        	set("value", 100000);
             set("no_drop",1);
        	set("material", "iron");
                     set("long", "这是一把长长的钉钯。\n");
                 set("wield_msg","$N将$n装备上。\n");
                  set("unwield_msg", "$N将$n卸了下来。\n");
      }
            init_rake(300);
	setup();
}
int query_autoload() { return 1; }
