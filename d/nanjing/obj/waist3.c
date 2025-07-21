// belt.c example belt

#include <ansi.h>

inherit EQUIP;

void create()
{
	set_name(HIR"鞓带"NOR, ({ "ting dai", "waist", "dai", "helt" }));

        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 2000);
                set("material", "cloth");
                set("armor_type", "waist");
                set("armor_prop/personality", random(3));
                set("armor_prop/armor", 10);
                set("armor_prop/dodge", 20);
                set("wear_msg","$N围上一条$n。\n");
                set("remove_msg","$N将$n解了下来。\n");
        }

        setup();
}
int query_autoload() { return 1; }