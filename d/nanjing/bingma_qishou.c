inherit ROOM;

void create()
{
	set("short", "旗手卫");
	set("long", @LONG
旗手卫系洪武十八年由旗手千户所改置。掌大驾金鼓、旗纛，佥民间壮丁为力
士随皇帝出入并守卫四门。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_changan3",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

