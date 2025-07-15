inherit ROOM;

void create()
{
	set("short", "内宫诸监");
	set("long", @LONG
这里是内宫二十四衙门中除十二监外的，四司八局的所在。四司为
惜薪司、宝钞司、钟鼓司、混堂司。八局为兵仗局、巾帽局、针工局、
内织染局、酒醋面局、司苑局、浣衣局、银作局。
LONG );
	set("exits", ([
		"north" : __DIR__"gov_zhujian1",
		"west" : __DIR__"road_huangxi5",
		"south" : __DIR__"road_huangnan1",
	]));
	setup();
	replace_program(ROOM);
}

