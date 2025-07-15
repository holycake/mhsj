inherit ROOM;

void create()
{
	set("short", "庭院");
	set("long", @LONG
这里是正厅前的庭院，被通往东西厢房的游廊包围着。庭院中间用大块的青石铺出
一条平坦的小路。路的一边有几组太湖石组成的假山零星地散落在花木之中，石组的摆
放无论从何处看去皆成景色。庭院中的花木不甚大，寥寥数株卻隐隐有山林之象。看来
该园的主人于造院之道颇有研究。西厢房可以看见外面的秦淮河，东厢房紧邻街道。北
边是正厅。
LONG );
	set("exits", ([
		"north" : __DIR__"room_zhengting",
		"south" : __DIR__"room_yang_gate",
	]));
        set("outdoors", "nanjing");
        set("valid_startroom", 1);
        set("no_time",1);
	setup();
}

