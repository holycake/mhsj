#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "马记饭馆");
	set("long", @LONG
这家饭馆在南京已经经营了几代人。虽然饭馆不大，可是来吃的人却是络绎不
绝，生意兴隆。由于这里靠近国子监，故此有不少监生时常来光顾。这家酒水免费
。只要示意(yao)一下即可。
LONG );
	set("exits", ([
		"east" : __DIR__"bridge_zhu",
		"west" : __DIR__"bridge_xinfu",
		"south" : __DIR__"road_shiyong1",
	]));
	set("objects", ([
		__DIR__"npc/boss_mafan" : 1,
		__DIR__"npc/npc_jiansheng" : 3,
	]));
	setup();
}

