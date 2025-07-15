inherit ROOM;

void create()
{
	set("short", "刑部");
	set("long", @LONG
刑部的职责是审定各种法律，复核各地送部的刑名案件，会同九卿审理“监
候”的死刑案件以及直接审理京畿地区的待罪以上案件。刑部的内部组织机构的
设置是按省设司。作為主管全國刑法的机构，与都察院管稽察、大理寺掌重大
案件的最后审理和复核，共为「三法司制」。
LONG );
	set("exits", ([
		"west" : __DIR__"di_taiping2",
		"north" : __DIR__"tianlao",
	]));
	setup();
	replace_program(ROOM);
}

