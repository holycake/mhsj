#include <ansi.h>
#include <weapon.h>

//inherit F_UNIQUE;
inherit STAFF;

void create()
{
	set_name( HIR "胜利女神" NOR, ({ "shengli nvshen", "staff" }) );
    set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "条");
		set("no_sell",1);
                set("no_drop", 1);
                set("no_give", 1);
                set("no_put", 1);
		set("long", HIY "此乃胜利女神所化成的。\n" NOR);
		set("value", 1000);
		set("material", "brass");
		set("wield_msg", HIY "\n$N拿出一条胜利女神握在手中，刹那间四周一片肃穆，连天地鬼神也为之震动。\n\n" NOR);
		set("unwield_msg", HIY "\n$N放下手中的胜利女神，周围的人才喘过一口气来。\n\n" NOR);
	}

    init_staff(200);
	setup();
}
