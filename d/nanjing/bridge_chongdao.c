inherit ROOM;

void create()
{
	set("short", "崇道桥");
	set("long", @LONG
崇道桥又称仓桥，因冶山道院得名。南为仓巷。仓巷位于朝天宫正南，因直通
苑仓得名，又叫将军仓巷，苑仓是三国孙权时重要的粮仓。三国时，仓巷北接皇仓
，是当时繁忙的运粮通道。国朝开国之前，鼓楼小粉桥到管家巷至大王府巷、仓巷
，此一线是笔直的南北主干道，两侧商肆林立，繁华景象延至清代。在本朝，仓巷
已经形成八条小巷，街巷格局数百年来一直稳定存在至今。本朝灯市初在仓巷，后
才移至夫子庙。这里是工商店铺、民居、文人汇聚之地。《儒林外史》便多次提到
仓巷，将之形容为“人文萃聚之区也，冶山之气钟毓所凝，户列簪缨，家兴弦诵”。
LONG );
	set("exits", ([
		"north" : __DIR__"road_long1",
		"south" : __DIR__"road_sanshan1",
		"east" : __DIR__"bridge_taiping",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

