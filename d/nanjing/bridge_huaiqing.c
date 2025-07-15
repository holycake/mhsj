inherit ROOM;

void create()
{
	set("short", "淮清桥");
	set("long", @LONG
淮清桥因古青溪与秦淮河在此汇流而得名。桥建于南朝时期，原名淮青桥，
但后人通称它为淮清桥。古桥畔有亭，供人歇息。桥亭有联，集唐代诗人刘禹锡
、韦庄的名句："淮水东边旧时月，金陵渡口去来潮"。
LONG );
	set("exits", ([
		"south" : __DIR__"river_qinhuai2",
		"west"  : __DIR__"road_dazhong3",
		"north" : __DIR__"shop_liji",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

