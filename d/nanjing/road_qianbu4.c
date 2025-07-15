inherit ROOM;

void create()
{
	set("short", "千步廊");
	set("long", @LONG
这里是外禁垣内的御道，道的两旁各建有左右两条千步廊。其中文官为主的
六部各衙门分布在左千步廊以东，五军都督府等军机事务衙门则分布在右千步廊
以西。两侧共计有东西向廊房百一十间，东西折向北廊房各三十有四间。这里向
北直通外禁垣――皇城的正门承天门。往南通往皇城的正门――洪武门。
LONG );
	set("exits", ([
		"east"  : __DIR__"gov_li2",
		"west" : __DIR__"gov_duduqian",
		"south" : __DIR__"road_qianbu5",
		"north" : __DIR__"road_qianbu3",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

