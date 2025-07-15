//By waiwai@mszj 2000/11/12


inherit ITEM;
#include <ansi.h>
void create()
{
        set_name(BLINK HIR "火" NOR , ({ BLINK HIR "fire" NOR, "huo" }) );
        set("long", BLINK HIR "一团熊熊燃烧的火 \n" NOR);
        set("no_get",1);
        
        setup();
}

