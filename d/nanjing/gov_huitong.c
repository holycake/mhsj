inherit ROOM;

void create()
{
	set("short", "会同馆");
	set("long", @LONG
这里是会同馆专门接待外地或外邦来京公干人员居住的馆舍。会同馆衙署在兵部衙
署之中。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_huitongguan",
	]));
	setup();
	replace_program(ROOM);
}

