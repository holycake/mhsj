inherit ROOM;

void create()
{
	set("short", "内宫诸监");
	set("long", @LONG
这里是内宫二十四衙门中除四司八局外的，十二监的所在。司礼监、内官监、
御用监、司设监、御马监、神官监、尚膳监、尚宝监、印绶监、直殿监、尚衣监、
都知监。
LONG );
	set("exits", ([
		"south" : __DIR__"gov_zhujian2",
		"west" : __DIR__"gate_xihua",
		"east" : __DIR__"gate_xian",
	]));
	set("objects", ([
		__DIR__"npc/wangchengen" : 1,
	]));
	setup();
	replace_program(ROOM);
}

