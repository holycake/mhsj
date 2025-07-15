inherit ROOM;
void create()
{
	set("short", "集贤客栈客房");
	set("long", @LONG
这里是集贤客栈的二楼客房。房间不大，陈设简单。这里由于地处闹市，因此
只有深夜才会安静，不过关上窗倒也不显嘈杂。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"kz_jixian",
	]));
	setup();
}
int valid_leave(object me, string dir)
{
//	if ( dir == "out" ) me->delete_temp("rent_paid");
	return ::valid_leave(me, dir);
}
