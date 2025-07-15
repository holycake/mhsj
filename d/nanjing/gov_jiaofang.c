inherit ROOM;

void create()
{
	set("short", "教坊司");
	set("long", @LONG
这里是宫廷音乐机构。始建于唐代，称为教坊，专门管理宫廷俗乐的教习和演
出事宜。一度改名“云韶府”。宋元两代亦设教坊；国朝改教坊为教坊司，隶属于礼
部，主管乐舞和戏曲。一些犯官的女眷会被送到这里落籍。这里时常还会对民间
演出以赚取收入。
LONG );
	set("exits", ([
		"east" : __DIR__"road_changan2",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

