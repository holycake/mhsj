// Room: /d/nanhai/xiaol.c

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG

这是一条通往后山的小路。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northdown" : __DIR__"xiaol2",
  "east" : __DIR__"guangchang",
]));
	set("asdlk", "asdf");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
