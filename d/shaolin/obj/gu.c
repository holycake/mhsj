#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("牛皮巨鼓", ({ "gu"}) );
        set_weight(300);
        set_max_encumbrance(80000);
	set("unit", "个");
	set("long", "少林寺击鼓楼中的巨鼓，相传是印度神牛皮所制。\n");
	set("closed", 1);
	set("value", 20000);
}

int is_container() {return 1;}

void init()
{
	if(this_player()==environment())
		 add_action("do_open","cut");
}
int do_open(string arg)
{
	object		me, ob;
        if( !arg || arg != "gu" )
                return notify_fail("你要割开什么？\n");
	me = this_player();
	ob = this_object();
	message_vision("$N“刺拉”一声，将$n从中间划开．．．。\n", me, ob);
		ob->set("closed",0);
        set("long", "少林寺击鼓楼中的巨鼓，相传是印度神牛皮所制。
可惜的是鼓面已经被人剥走了。。。\n");
        return 1;
}

int is_closed()
{
	return ((int) this_object()->query("closed"));
}
