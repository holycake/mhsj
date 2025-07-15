// yszz 1.0
 
#include <weapon.h>

inherit HAMMER;

void create()
{
        set_name("[34m骷髅锤[m", ({ "hammer" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "这是一把罗煞鬼婆炼制的独门怪兵器骷髅锤.\n");
                set("value", 1200);
                set("material", "iron");
                set("wield_msg", "$N拿出一把$n，试了试重量，然后握在手中。\n");
                set("unwield_msg", "$N放下手中的$n。\n");
        }
        init_hammer(75);
        setup();
}

