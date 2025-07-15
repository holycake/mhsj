inherit ROOM;

void create()
{
	set("short", "夫子庙");
	set("long", @LONG
这里是祭祀孔子的孔庙。孔子被人们尊称为孔夫子，故其庙宇俗称"夫子庙"。
由于儒学的正统地位，孔子备受历朝历代统治者和士子们的尊崇，祀奉他的孔庙
大多与教育设施如学宫、贡院等布置在一起，即所谓的庙附于学，一般是在学宫
的前面或一侧。庙前广场边上是作为泮池的内秦淮河。对岸的一堵红墙，是建于
万历年间的大照壁，气势磅礴，为全国之最。
LONG );
	set("exits", ([
		"north" : __DIR__"qianzhuang_tongli",
		"southeast" : __DIR__"bridge_wende",
		"south" : __DIR__"fuxue",
		"east" : __DIR__"gongyuan",
		"west" : __DIR__"road_yujie3",
	]));
	setup();
	replace_program(ROOM);
}

