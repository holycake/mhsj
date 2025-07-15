inherit ROOM;

void create()
{
	set("short", "媚香楼客房");
	set("long", @LONG
这里是媚香楼的二楼客房。房间不大，陈设简单。从窗外可以看到外面的钞
库街。不时地传来街上乐器店的笛声。这条街上开着不少南京的特色小吃店。很
多店铺门口都有卖盐水鸭和叫化鸡。
LONG );
	set("sleep_room", 1);
	set("no_fight", 1);
        set("hotel",1);
	set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"lou_meixiang",
	]));
	setup();
}

int valid_leave(object me, string dir)
{
//	if ( dir == "out" ) me->delete_temp("rent_paid");

	return ::valid_leave(me, dir);
}
