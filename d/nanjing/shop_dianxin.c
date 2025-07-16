inherit ROOM;

void create()
{
	set("short", "点心铺");
	set("long", @LONG
你踏入点心铺，甜香扑鼻，令人垂涎。柜台上摆满松软的云片糕、桂花糖
藕与酥饼，竹盘中色泽诱人。伙计笑脸迎客，吆喝声此起彼伏，市井气息浓厚
。铺外行人川流，廊下食客啜着茶汤，低语品评，尽显金陵街肆的热闹。
LONG );
	set("exits", ([
		"south" : __DIR__"road_chongli4",
	]));
	setup();
	replace_program(ROOM);
}

