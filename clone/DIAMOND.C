// diamond.c

#include <ansi.h>
inherit MONEY;

void create()
{
        set_name(HIW"钻石"NOR, ({"diamond", "zuanshi", "diamond_money"}));
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("money_id", "diamond");
                set("long", HIM"亮晶净的钻石，人见人爱的钻石，啊～～钻石！\n"NOR);
                set("unit", "克拉");
                set("base_value", 10000000 );
                set("base_unit", "克拉");
                set("base_weight", 5);
        }
        set_amount(1);
}


