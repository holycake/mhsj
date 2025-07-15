inherit ROOM;

void create()
{
	set("short", "聚宝桥");
	set("long", @LONG
此桥原名长干桥北面是京城的南大门聚宝门。步上桥面，顿觉宽阔开朗，气度
不凡，长干桥始建于南唐，为南唐宫殴御街直达城外长干里的必经之道。南宋年间
，户部尚书马光祖重建，更名长安桥，为五拱石桥；明初复建，名此。
LONG );
	set("exits", ([
		"east"  : __DIR__"road_changganli2",
		"south" : __DIR__"yuhuatai",
		"west"  : __DIR__"road_changganli1",
		"north" : __DIR__"gate_jubao",
	]));
        set("outdoors", "nanjing");
	setup();
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "north" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
