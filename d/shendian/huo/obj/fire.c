inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIR "熔岩" NOR , ({ BLINK HIR "fire" NOR, "huo" }) );
        set("long", BLINK HIR "一块熊熊燃烧的熔岩 \n" NOR);
        set("no_get",1);
        setup();
}