// budd_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
 set_name( HIR "丹心天魔杵" NOR, ({ "tianmo chu", "staff" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
    set("long", HIR"这是一根攻击力极强的武器。\n"NOR);
     set("value", 30000);
		set("material", "brass");
set("wield_msg", "$N将$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

     init_staff(130);
	setup();
}
