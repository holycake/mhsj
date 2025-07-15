inherit ROOM;

void create()
{
	set("short", "莫愁湖");
	set("long", @LONG
隋唐以前，长江沿南京城西侧流过，与秦淮河汇合于石头城下，后长江改道北
移，留下大片淤积地与一系列沼泽、池塘与湖泊，莫愁湖即其中最大者，南唐时称
横塘，因其依傍石头城，故亦称石城湖。北宋《太平寰宇记》记载：“莫愁湖在三
山门外，昔有卢妓莫愁家此，故名。”明初，莫愁湖进行了大规模开发建设，沿湖
畔筑楼台十余座，一时热闹非凡。被誉为“金陵第一名胜”、“第一名湖”。
LONG );
	set("exits", ([
		"south" : __DIR__"road_jiangdong",
		"north" : __DIR__"gate_shicheng",
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
