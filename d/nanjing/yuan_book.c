#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "书房");
        set("long", @LONG
这是小楼里的一处书房，里边藏书颇丰。
LONG
        );
        set("exits", ([
		"south" : __DIR__"yuan_n",
	]));
	set("objects", ([
		__DIR__"npc/linshiwei" : 1,
	]));
	create_door("south", "书房的门", "north", DOOR_CLOSED);
       set("valid_startroom", 1);
       set("no_time",1);
	set("sleep_room", 1);
       set("no_clean_up", 0);
       setup();
}

void init()
{
        add_action("do_bed", "sleep");
}

int do_bed()
{
	object me = this_player();

	message_vision( sprintf(HIR"$N手托着头靠在几上，闭眼休息。书墨香夹杂着少女淡淡的体香化做睡意阵阵袭来，不多时$N便睡了过去。\n"NOR),me);
	me->set_temp("block_msg/all",1);
	return 0;
}

int valid_leave(object me, string dir)
{
	object target,ob;
	me->delete_temp("ask_sex");
	me->delete_temp("look_sex");

	if(sizeof(filter_array(all_inventory(environment(me)),(:  $1->is_character() :)))<3)
	{
		target=present("lin shiwei", environment(me));
		if(objectp(ob = present("skirt", target)) )
			ob->unequip();
		message_vision(HIM "林仕薇见四下无人，便又将淫书从抽屉中拿出来翻看。\n\n" NOR, me);
	}
	return ::valid_leave(me, dir);
}
