inherit ROOM;

void create()
{
	set("short", "乐贤堂");
	set("long", @LONG
这家店摆满了各式各样的书籍，同时还售卖文房四宝和各种纸张。
LONG );
	set("exits", ([
		"south" : __DIR__"gongyuan",
		"east" : __DIR__"river_qinhuai3",
	]));
	set("item_desc", ([ /* sizeof() == 1 */
		"xuegui": "
		日讲经书三起，日看纲目数页。
		通晓时务物理，参读古文诗赋。
		读书必须过笔，会课按时蚤完。
		夜读仍戒晏起，疑误定要力争。

	求学需缴学费纹银二十两。\n",
	]));
	set("objects", ([ /* sizeof() == 1 */
		__DIR__"npc/boss_book" : 1,
	]));
	setup();
	replace_program(ROOM);
}

