inherit ROOM;

void create()
{
	set("short", "左军都督府");
	set("long", @LONG
五军都督府建立于洪武十三年，用于管理卫所。每都督府设左、右都督、正一
品，并设有五军断事官。五军都督府彼此平行，互不统辖，各自与兵部直接联系，
最后奏请皇帝裁定。有统兵权但无调兵权，兵部有调兵权而无统兵权，两者互相制
衡，以避免权力过大。左军都督府：掌浙江都司、辽东都司、山东都司。
LONG );
	set("exits", ([
		"east" : __DIR__"road_qianbu2",
	]));
	setup();
	replace_program(ROOM);
}

