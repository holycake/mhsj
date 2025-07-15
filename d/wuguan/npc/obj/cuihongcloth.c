//Cracked by Roath
// cuihongcloth.c  翠红衫
//
// by yfengf

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(HIG"翠"NOR+HIR"红衫"NOR, ({ "cloth" }) );
        set_weight(3300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

