inherit ROOM;

void create()
{
	set("short", "建康武馆");
	set("long", @LONG
据说这家武馆从太祖时起就一直开在这里。三世祖杨庭广曾经四处寻访名师
，于武当山拜得高人，尽得真传，学得武当绝学。后回金陵将其发扬光大。这里
处于城北，多为军队营地，习武之风盛行，因此生意兴隆。
LONG );
	set("exits", ([
		
		"east" : __DIR__"lou_zhong",
	]));
	set("objects", ([
		__DIR__"npc/boss_wuguan" : 1,
	]));
	setup();
	replace_program(ROOM);
}

