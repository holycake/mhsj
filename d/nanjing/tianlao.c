inherit ROOM;

void create()
{
	set("short", "天牢");
	set("long", @LONG
这里是刑部的大牢。专门关押重刑犯人的地方。位于太平门外的玄武湖滨，
俗称为“天牢”。由于太祖和成祖两代在南京杀了很多人，太平门外的哭声日夜不
绝，所以人们把通向天牢的那段太平堤称为“孤凄埂”。
LONG );
	set("exits", ([
		"south" : __DIR__"gov_xing",
	]));
	setup();
	replace_program(ROOM);
}

