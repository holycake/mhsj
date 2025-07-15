inherit ROOM;

void create()
{
	set("short", "北城客店客房");
	set("long", @LONG
这里是北城客店的二楼客房。房间不大，陈设简单。这里由于位置偏僻，因此
除了早市时间外，环境十分安静。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"kz_beicheng",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
//	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
