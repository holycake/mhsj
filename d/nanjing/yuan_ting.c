#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "湖心亭");
        set("long", @LONG
这里是湖中央小岛上的一个凉亭。小岛全由假山组成，萦绕曲折，竟有双层。在假
山中穿行，不知不觉便上了岸。岛的一角有一个巨石钓矶。
LONG
        );
        set("exits", ([
		"east" : __DIR__"yuan_e2",
		"west" : __DIR__"yuan_w2",
//		"south" : __DIR__"yuan_s",
	]));
	set("objects", ([
		__DIR__"npc/fu_zongli" : 1,
		__DIR__"npc/lifenfang" : 1,
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
		set("sleep_room", 1);
        set("resource/water", 1);
        setup();
}

void init()
{
        add_action("do_bed", "sleep");
}

int do_bed()
{
	object me = this_player();

	message_vision( sprintf(HIM"微风徐徐，草木摩娑。$N头枕小傅的大腿，将脸埋入花丛之中。$N闻着少女的体香渐渐进入梦里。\n"NOR),me);
	me->set_temp("block_msg/all",1);
	return 0;
}
