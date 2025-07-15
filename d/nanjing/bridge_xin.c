inherit ROOM;

void create()
{
	set("short", "新桥");
	set("long", @LONG
新桥跨内秦淮河南段。据传该桥三国时始建，名新桥。梁代称万岁
桥，后名饮虹桥。宋代复称新桥，南宋乾道五年，留守史正志重建。因
木桥不耐风雨侵蚀，于是建造桥屋，覆大屋数十楹，既保护桥身，延长
木桥使用寿命，又方便行旅憩息。开禧元年又重建，宝祐四年再整修。
万历四十四年改建为拱桥，拱石上留有碑记。
LONG );
	set("exits", ([
		"west"  : __DIR__"road_laifeng4",
		"northwest" : __DIR__"road_laifeng3",
		"east" : __DIR__"shop_tie",
		"southeast" : __DIR__"river_qinhuai1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

