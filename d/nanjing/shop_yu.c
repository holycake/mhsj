inherit ROOM;

void create()
{
	set("short", "鱼市街");
	set("long", @LONG
鱼市街因鱼市得名。北门桥下的进香河北通玄武湖，每日凌晨，玄武湖中捕鱼
捉虾湖民驾着小船，笼着晨雾“咿咿呀呀”摇到北门桥，这便进了城。赶鲜的人也从
四面八方汇拢来，大家验货谈价。人气一旺，久而久之就成了一处市面。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_beimen",
	]));
	setup();
	replace_program(ROOM);
}

