#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "朝阳门");
	set("long", @LONG
朝阳门为南京十三座内城门之一，因其位于南京城东，最先迎接太阳而得名。
前元至正二十六年，向东北两面拓展南京城时修筑朝阳门。城门为单孔券门，门
外还有一道。此门是瓮城连接城内的宫城和城外的明孝陵的通道。每年神宫监进
贡苗姜、时样果、香脂均从此门入。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"west" : __DIR__"gate_donghua",
	]));
	set("objects", ([
		__DIR__"npc/bing_shoucheng" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n应天巡抚\n海瑞\n";
}
