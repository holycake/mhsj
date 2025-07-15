// budd_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( HIG "魔幻杖" NOR, ({ "mohuan zhang", "staff" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", BLINK HIY"由本站的巫师特别为玩家制作的。\n"NOR);
		set("value", 0);
		set("material", "brass");
		set("wield_msg", "$N拿出一根金光灿然的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(80);
	setup();
}
