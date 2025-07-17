inherit ROOM;

void create()
{
	set("short", "大理寺");
	set("long", @LONG
大理寺是三法司之一，掌管刑狱案件的审理与复核。寺内庄严肃穆，正堂高悬
“明镜高悬”匾额，象征司法公正。长官大理寺卿位列九卿，他每日在此主持案件复
核，听取下级官员的汇报，并与其他两法司（刑部、都察院）协同处理重大案件。
LONG );
	set("exits", ([
		"south" : __DIR__"di_taiping3",
	]));
	set("outdoors", "nanjing");
	setup();
	replace_program(ROOM);
}

