// guangchang.c 广场
// by Arnzh

inherit ROOM;

void create()
{
	set("short", "太子岩");
	set("long", @LONG
这是一块广场般大小的大石，上面又平又光，显然不是人力搬来，
也不是人力制成。
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"southdown" : __DIR__"shijie7",
		"northwest" : __DIR__"nanyan",
		]));
	setup();
	
}


