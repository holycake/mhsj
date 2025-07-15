inherit ROOM;

void create()
{
	set("short", "客房");
	set("long", @LONG
这里是画舫二层的客房，是专为八艳的客人准备的休憩之处。往后走有一排
房间，是主人们和丫鬟的闺房，令人浮想联翩。
LONG );
	set("exits", ([
		"north"  : __DIR__"huafang5",
	]));

	set("sleep_room", 1);
	set("no_fight", 1);
	set("hotel",1);
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
