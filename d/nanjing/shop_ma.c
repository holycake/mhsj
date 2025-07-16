inherit ROOM;

void create()
{
	set("short", "马市");
	set("long", @LONG
你来到金陵马市，尘土飞扬，嘶鸣声不绝。市中骏马成群，毛色光亮，商
贾与马贩高声议价，热闹非凡。木栅旁，马夫手持皮鞭，试马步伐，矫健之姿
令人赞叹。几名兵丁巡查，维护市集秩序，透出明代武备的严整。
LONG );
	set("exits", ([
		"east" : __DIR__"road_hongwu3",
	]));
	set("objects", ([
		__DIR__"npc/boss_ma" : 1,
	]));
	setup();
	replace_program(ROOM);
}

