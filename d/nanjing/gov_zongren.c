inherit ROOM;

void create()
{
	set("short", "宗人府");
	set("long", @LONG
宗人府是管理皇家宗室事务的机构。掌管皇帝九族的宗族名册，按时撰写帝
王族谱，记录宗室子女嫡庶、名字、封号、世袭爵位、生死时间、婚嫁、谥号安
葬之事。职掌收发文件、管理宗室内部诸事、登记黄册、红册、圈禁罪犯及教育
宗室子弟。凡是宗室陈述请求，替他们向皇帝报告，引进贤才能人，记录罪责过
失之机构。
LONG );
	set("exits", ([
		"west" : __DIR__"road_qianbu1",
	]));
	setup();
	replace_program(ROOM);
}

