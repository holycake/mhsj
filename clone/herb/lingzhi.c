// lingzhi.c

inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG "灵芝" NOR, ({ "lingzhi", "herb_lingzhi" }));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "这是中药药材。\n");
                set("unit", "块");
                set("value", 20000);
                set("weight", 70);
        }
        setup();
}
