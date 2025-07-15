// qianjinzi.c

#include "herb.h"

void create()
{
	set_name(HIY "千金子" NOR, ({ "qian jinzi", "herb_qianjinzi" }));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "这是中药药材。\n");
		set("unit", "颗");
		set("value", 3000);
        	set("weight", 20);
set("base_unit","颗");
	}
	setup();
}
