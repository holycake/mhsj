inherit ROOM;

void create()
{
	set("short", "奉天殿");
	set("long", @LONG
这里是皇宫的正殿奉天殿，坐落于三台之上，面阔九间，进深五间。宫殿四
周围以城墙，高二丈五尺，顶宽二丈一尺五分。重檐庑殿顶。前门为奉天门，左
为东角门，西角门。门外两庑有左翼门、右翼门，南为内五龙桥。大殿左为中左
门，殿右为中右门。殿前为广庭，东为文楼，西为武楼。奉天殿之后有华盖殿，
坐落于三台之上，面阔五间，进深五间。攒尖顶。华盖殿之后为谨身殿，坐落于
三台之上，面阔七间，进深五间。重檐歇山顶。殿左为后左门，殿右为后右门。
这三个殿合称“前三殿”。

LONG );
	set("exits", ([
		"east" : __DIR__"gov_wenhua",
		"west" : __DIR__"gov_wuying",
		"north" : __DIR__"gate_qianqing",
		"south" : __DIR__"road_guangchang",
	]));
	set("objects", ([
		__DIR__"npc/bing_dahan" : 2,
	]));
	setup();
	replace_program(ROOM);
}

