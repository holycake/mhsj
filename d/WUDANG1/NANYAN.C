// tyroad2.c 石阶
// by Marz 

inherit ROOM;

void create()
{
	set("short", "南岩峰");
	set("long", @LONG
	这是一条宽大坚实的石阶路，不时地有进香客和游人从你的身边走过。抬头西望，
雄伟的三清殿顶浮现在香烟袅绕之中，巍峨壮观；东边一条石阶通往山下，隐约可见远处
桃花片片，赏心悦目。
LONG
	);
	set("outdoors", "wudang");

	set("exits", ([
		
		"southeast" : __DIR__"taiziyan",
		"northup" : __DIR__"chaotian",
	]));
	
//	set("objects", ([
//		__DIR__"npc/guest" : 1]));
		
	setup();
	replace_program(ROOM);
}

