
#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("佛光禅杖" , ({ "lightstaff", "staff" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("long", "一条很不起眼的禅杖，上书“佛光”\n");
		set("value", 6000);
		set("material", "iron");
		set("wield_msg", "$N拿出一根乌黑的$n握在手中。\n");
		set("unwield_msg", "$N放下手中的$n。\n");
	}

	init_staff(23);
	setup();
}
