// Room: /luohanta/talup.c

inherit ROOM;

void create()
{
	set("short", "罗汉塔");
	set("long", @LONG


                        佛


LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"tal9",
]));
	
	set("no_clean_up", 0);
	set("jingzuo_room",1);
	setup();

}
