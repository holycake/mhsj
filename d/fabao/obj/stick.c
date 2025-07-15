// by gslxz@mhsj 2001/10/17
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
      set_name(HIY"金铁棒" NOR, ({ "bixuejian","sword","jian" }) );
    set_weight(20000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "个");
        	set("value", 100000);
             set("no_drop",1);
        	set("material", "iron");
                 set("long", "这是一把由玄铁制成的极锋利的剑。\n");
                 set("wield_msg","$N将$n装备上。\n");
                  set("unwield_msg", "$N将$n卸了下来。\n");
      }
    	init_sword(300);
	setup();
}
int query_autoload() { return 1; }
