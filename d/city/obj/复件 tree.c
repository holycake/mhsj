#include <ansi.h>

inherit ITEM;


void create()
{
          set_name(HIW"千年樱花树"NOR, ({ "tree","shu",  }) );
        set_weight(3000000);
        set_max_encumbrance(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "个");
                set("long", HIM"一株千年樱花树，清风一吹，片片花瓣随风飘落。\n"NOR);
                set("material", "wood");
                set("no_get",1);
                set("no_drop",1);
                set("amount",30);
        }
        setup();

}

