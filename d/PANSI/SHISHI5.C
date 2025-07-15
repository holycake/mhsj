// shishi5.c
// by shilling 97.2

inherit ROOM;

void create()
{
	set("short", "紫云轩");
	set("long", @LONG
这里是地下石室的最下面一层了，你眼前忽然一亮，这里布置得华丽中
不乏清雅，平实中透着高贵。楠木方桌，大太师椅，以及墙上的字画都
透着一股非凡之气。
LONG );
	set("exits", ([
		"up" : __DIR__"shishi4",
	]));
	set("objects",([
		__DIR__"npc/zixia" : 1,
		"/d/pansi/obj/yinsuo.c":1, 
	]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
