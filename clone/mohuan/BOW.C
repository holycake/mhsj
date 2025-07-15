#include <weapon.h>
#include <ansi.h>

inherit BOW; 

void create()
{
        set_name(HIG"魔幻神弓"NOR, ({"gong"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long",BLINK HIR"这是本站巫师为玩家制作的精良的兵器。\n"NOR);
                set("unit", "张");
		set("value", 0);
                set("wield_msg", "$N抓起一张$n，握在手中当武器。\n");
                set("material", "steel");
        }

        init_bow(1);
        setup();

}

