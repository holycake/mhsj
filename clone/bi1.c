#include <armor.h>
#include <ansi.h>

inherit NECK;

void create()
{
        set_name(HIY"纪念币"NOR, ({ "jingnian bi", "bi" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("long",HIR "这是本站开站时所发行的硬币。\n" NOR);
                set("material", "steel");
		set("no_sell", 1);
                set("armor_prop/armor", 3);
                  set("armor_prop/intelligence", 30);
		set("armor_prop/personality", 1);
        }
        setup();
}

