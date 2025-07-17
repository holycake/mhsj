#include <ansi.h>
#include <room.h>

inherit ROOM;

string do_look();

void create()
{
	set("short", "知返轩");
	set("long", @LONG
这里是花园最北边的一座小楼，是园主人平常看书、听琴的所在。门上的匾额
上书“知返轩”三个大字。楼前一块空地用平整的青条石砖铺就。里面有扇门(door)
似乎是书斋。南边假山林立，看起来是个迷宫。
LONG);
	set("exits", ([
		"north" : __DIR__"yuan_book",
		"south" : __DIR__"yuan_rockery",
		"east" : __DIR__"yuan_ne",
		"west" : __DIR__"yuan_nw",
	]));
	set("item_desc", ([
		"door" : (: do_look :),
	]));
	create_door("north", "书房的门", "south", DOOR_CLOSED);
	set("valid_startroom", 1);
	set("no_time",1);
	set("sleep_room", 1);
       set("no_clean_up", 0);
	setup();
}

string do_look()
{
	object me,env;
	mapping exits;
	me = this_player();
	env = environment(me);
	if (mapp(exits = env->query("exits")) && ! undefinedp(exits["north"]))
	{
                if (objectp(env = find_object(exits["north"])))
		if(sizeof(filter_array(all_inventory(env),(:  $1->is_character() :))) ==1)
		{
			message_vision(HIM "$N隔着门往书斋中瞧，只见一少女娇躯靠着椅子，衣衫零乱，裙子掀起，下体暴露。\n\n" NOR, me);
			message_vision(HIM "少女左手食、中二指隔着衣服摩挲著乳头，右手中指在湿答答的桃源洞内尽情挑动，口中不时娇喘连连。\n\n" NOR, me);
			message_vision(HIM "$N见淫书或开或合，散了一地，即知她一人在书斋里，太过寂寞无聊，所以翻看淫书来消磨时间，一时动了春心，故而自求慰解。\n" NOR, me);
			me->set_temp("look_sex",1);
		}
		else
		{
			message_vision(HIM "$N隔着门往书斋中瞧，只见一少女在里面看书。似乎还有其他人的声音。\n\n" NOR, me);
		}
        }

	return "";
}
