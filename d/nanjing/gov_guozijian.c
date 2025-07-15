inherit ROOM;

void create()
{
	set("short", "国子监");
	set("long", @LONG
国子监是国朝的太学，掌教育。祭酒掌国子监，从四品。副手司业，正六品。
另有五经博士、助教、学正等官。下设五厅（绳愆厅、博士厅、典簿厅、典籍厅
、掌馔厅）、六堂（率性、修道、诚心、正义、崇志、广业）。
LONG );
	set("exits", ([
		"south" : __DIR__"gov_shuaixing",
		"west" : __DIR__"road_chengxian1",
	]));
	set("objects", ([
		__DIR__"npc/guan_wangyangming" : 1,
		__DIR__"npc/npc_jiansheng" : 5,
	]));
	setup();
	replace_program(ROOM);
}
