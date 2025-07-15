#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIY"主控电脑"NOR, ({ "computer" , "电脑"}) );
	set_weight(50000);
	set_max_encumbrance(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "台");
		set("long",BLINK HIY"这台电脑管理着本站的整个系统，是本站的核心电脑。\n"NOR);
		set("value", 1000);
	}
}

int is_container() { return 1; }
