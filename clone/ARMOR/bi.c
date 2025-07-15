#include <armor.h>
#include <ansi.h>
inherit NECK;

void create()
{
        set_name(HIY"纪念币"NOR, ({"jinian bi","bi"}));
        set_weight(800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
		set("value", 2000);
                set("long", HIY"魔幻西游傳"NOR+YEL"開站留念。\n");
		set("no_sell", 1);
                set("no_give", 1);
                set("no_drop", 1);
		set("material", "steel");
		set("armor_prop/spells", 5);
		set("armor_prop/armor", 1);
               set("armor_prop/personality", 1);
                set("armor_prop/intelligence", 10);
		
        }
	setup();
}

