#include <armor.h>
#include <ansi.h>

inherit HEAD;

void create()
 {
          set_name(HIB"智者"HIR"之冠"NOR, ({ "wisdom bonnet", "bonnet", "hat" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顶");
                  set("long", HIC"一顶智慧之丝做成的冠。\n"NOR);
                set("material", "steel");
                  set("value", 0);
                  set("armor_prop/armor", 15);
                  set("armor_prop/intelligence", 17);
        }
        setup();
}