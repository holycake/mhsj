inherit ROOM;

void create()
{
	set("short", "行人司");
	set("long", @LONG
你步入行人司，官署内文牍堆积，墨香弥漫。书案旁，吏员手持朱笔，忙
于誊写外交文书，气氛凝重。墙上悬挂一幅大明舆图，标示四夷疆域。窗外街
市喧嚣隐约可闻，却与此处的肃静形成鲜明对比。几名行人低头核对文书，准
备奉旨出使。
LONG );
	set("exits", ([
		"east" : __DIR__"road_changan3",
	]));
	setup();
	replace_program(ROOM);
}

