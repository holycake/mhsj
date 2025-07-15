// pao.c
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(HIR"红外氅"NOR, ({"red cloth", "cloth", "pao"}));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 50);
		    set("long", "一件红色外套。\n");
                set("material", "cloth");
                set("armor_type", "cloth");
                set("armor_prop/armor", 2);
             }
}
