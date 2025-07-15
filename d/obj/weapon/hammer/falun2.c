#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;

inherit HAMMER;

void create()
{
        set_name(HIY "法轮" NOR, ({"falun", "lun","hammer"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long","虽说是普通的法器，但在大势至菩萨的手里怎么也要沾些灵气。\n");
                set("unit", "个");
	set("replace_file", "/d/obj/weapon/hammer/falun");
                set("value", 50000);
                set("wield_msg", "$N拿出一个$n，握在手中晃了几下。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
		    set("material", "steel");
                            set("armor_prop/spells", 10);
}
init_hammer(150);
        set("is_monitored",1);
        setup();
}
