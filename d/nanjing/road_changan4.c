inherit ROOM;

void create()
{
	set("short", "长安街");
	set("long", @LONG
这是一条宽阔的青石街道，向南北两头延伸。北边是北城门通向城外。
南边显得很繁忙。东边是一座两层的楼阁，挂着“太白遗风”的招帘，门
额上悬挂一方横匾，“醉仙楼”三字擦得闪闪发亮，乃是苏学士的手笔。
阵阵酒肉香酒香让你垂涎欲滴。西边是一座古朴的庙宇，香火缭绕，那就
是天下学武之人所共同敬仰的武庙了。
LONG );
	set("exits", ([
		"east"  : __DIR__"gov_qintian",
		"southwest" : __DIR__"road_changan1",
		"south" : __DIR__"lou_laibin",
		"north" : __DIR__"road_changan3",
	]));
        set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}
