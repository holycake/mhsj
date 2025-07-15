// Room: /d/liwu/lipinroom.c

inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", HIR"节日礼品屋"NOR);
	set("long", @LONG
这是一幢红白相间的小房子，你从窗子向里望去，见里面挂满拉花彩灯，
充满节日气氛。门口有一个和蔼的老人正在发红包，拿红包的人都笑开了颜，
:赶快进去拿一个吧！（ask man about 红包）    
LONG);

	set("exits", ([
		
                "southwest"      :__DIR__"happyjie",
	]));

	set("objects", ([
		__DIR__"npc/xmas_men" : 1,
		__DIR__"npc/happyboy" : 1,
		__DIR__"npc/happygirl" : 1,

	]));


	setup();
	replace_program(ROOM);
}

