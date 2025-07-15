inherit ROOM;

void create()
{
	set("short", "北门桥市");
	set("long", @LONG
这里原是南唐金陵城的北门。此桥为当时皇宫北门外的玄武桥。由于玄武之名
系皇家专用，故此改名为北门桥。侧畔的进香河，直通鸡鸣寺。是为了方便城外的
百姓进香而辟。大多香客乘船由此经过。出了北门桥，就很有点荒郊野外的意思了。
鸡鸣寺高高地孤悬山顶。冬日残阳刚刚西照，四周便杳无人迹，一派风声鹤唳。
北门桥左近的鱼市街，是城内居民购买河鲜、肉、菜的集市。。
LONG );
	set("exits", ([
		"east"  : __DIR__"shop_yaopu",
		"west"  : __DIR__"shop_yu",
		"south" : __DIR__"road_hongwu3",
		"north" : __DIR__"road_hongwu2",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

