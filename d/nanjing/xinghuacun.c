inherit ROOM;

void create()
{
	set("short", "杏花村");
	set("long", @LONG
杏花村位于今凤游寺北段， 村里的名产“金陵春”是上品佳酿，在全国堪称
“一地之长，一方之秀”。村子里有历朝历代种植的上百株杏花。这里传为唐代
诗人杜牧沽酒处。“清明时节雨纷纷，路上行人欲断魂。借问酒家何处有，牧
童遥指杏花村。”
LONG );
	set("exits", ([
		"south"  : __DIR__"shop_zayi",
		"west" : __DIR__"road_laifeng5",
		"east" : __DIR__"river_qinhuai1",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
