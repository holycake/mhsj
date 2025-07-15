#include <room.h>

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "通济门");
	set("long", @LONG
通济门是十三座京城城门之一，由明初原集庆路旧东门截城壕增建，扼守于
内外秦淮分界，门向东北为皇城，向西南则是商业区，为南京咽喉所在。通济门
上下均为条石砌筑，为福船型（鱼腹型）内瓮城城门，与三山门（今水西门）相
似，临近秦淮河用船形取同舟共济之意。也是南京内城门中占地面积最大的城门
，与聚宝门和三山门是三座规格最高的内瓮城城门。通济门内部结构极其繁复，
一座城楼，两条上城马道和人行道，三座瓮城，四道门垣皆为拱券砌筑，以及若
干瓮洞。
LONG );
	set("item_desc", ([
		"gaoshi" : (:look_gaoshi:),
	]));
	set("exits", ([
		"southeast" : __DIR__"si_xuanzhen",
		"west" : __DIR__"shop_liji",
		"north" : __DIR__"road_chongli1",
	]));
	set("objects", ([
		__DIR__"npc/bing_shoucheng" : 6,
		__DIR__"npc/bing_xunluo" : 6,
	]));
	set("outdoors", "nanjing");
	setup();
}

string look_gaoshi()
{
	return FINGER_D->get_killer() + "\n应天巡抚\n海瑞\n";
}

int valid_leave(object me, string dir)
{

	if ( me->query("limit") == "nanjing" && dir == "southeast" )
	        return notify_fail("\n");
	return ::valid_leave(me, dir);
}
