// by mhsj@gslxz 2001/3/12
#include <ansi.h>
#include <armor.h>;

inherit BOOTS;

void create()
{
       set_name(HIY"细麻男鞋"NOR, ({"shoes" }) );
           set("value", 0);
            set_weight(100);
        if( clonep() )
                  set_default_object(__FILE__);
        else {
                  set("unit", "双");
                  set("long", HIC"一双细麻编制的鞋。\n"NOR);
                             set("material", "steel");
                  set("armor_prop/armor", 5);
                  set("armor_prop/dodge", 2);
        }
        setup();
}