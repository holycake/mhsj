inherit ROOM;

void create()
{
	set("short", "文德桥");
	set("long", @LONG
文德桥始建于万历十三年，相传为太白醉酒捞月之地，后世在桥旁辟建得月
台以示纪念。文德二字取“文章道德天下第一”之意，但南京民间有“君子不过文德
桥”一说。因为桥北为江南科举重地，每有赶考学子聚集苦读；对岸则是名冠江南
的酒肆妓馆之地。分隔它们的，只一座文德桥。相传每年农历十一月十五日的深
夜子时，升至中天的圆月会把它在秦淮河里的影子一分为二，各投在文德桥的东
西两侧。无论从桥的哪侧往下看，河里都只有半枚月亮，称“文德分月”。
LONG );
	set("exits", ([
		"west"  : __DIR__"fuxue",
		"east"  : __DIR__"road_wuyi",
		"north" : __DIR__"gongyuan",
		"south" : __DIR__"lou_meixiang",
		"northwest" : __DIR__"fuzimiao",
		"northeast" : __DIR__"river_qinhuai4",
		"southwest" : __DIR__"bridge_wuding",
		"southeast" : __DIR__"road_shanhe1",
	]));
	set("objects", ([
		__DIR__"npc/npc_shaonv" : 2,
		__DIR__"npc/npc_girl" : 1,
		__DIR__"npc/npc_boy" : 1,
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

