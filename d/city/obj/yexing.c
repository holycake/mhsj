//By waiwai@mszj 2000/09/28

#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIB"夜行衣"NOR, ({ "cloth" }) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","这是一件绣着龙虎豹的黑色劲装衣。\n");
                set("unit", "件");
                set("material", "cloth");
                set("armor_prop/armor", 20);
        }
        setup();
}
