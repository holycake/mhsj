inherit ROOM;

void create()
{
	set("short", "梳篦老铺");
	set("long", @LONG
这家店是专卖男女梳发用木梳、首饰的店铺。门口的幌子为一“十”字架，四
端各悬一串木梳，每串约五六把，下缀幌绸；门前设一木座，上立木质白色仙鹤，
鹤嘴叼一根细红绒绳，中间挂竹篦、木梳各一个，系一小红布条。
LONG );
	set("exits", ([
		"west" : __DIR__"road_laifeng2",
	]));
	set("objects", ([
		__DIR__"npc/boss_su" : 1,
	]));
	setup();
	replace_program(ROOM);
}

