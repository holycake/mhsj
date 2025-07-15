//Cracked by Roath
// cloth.c
//
// by yfengf

#include <armor.h>
#include <ansi.h>

inherit CLOTH;

void create()
{
        set_name(CYN "青色布衣" NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 1);
        }
        setup();
}

