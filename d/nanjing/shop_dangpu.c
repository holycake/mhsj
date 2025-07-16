// Room: /city/dangpu.c
// YZC 1995/12/04 
#include <room.h>
inherit HOCKSHOP;

void create()
{
	set("short", "当铺");
	set("long", @LONG
这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面
前，柜台上摆着一个牌子(paizi)， 柜台后坐着唐老板，一双精明的
上上下下打量着你。
LONG
	);
	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
	set("item_desc", ([ /* sizeof() == 1 */
	  "paizi" : "
	本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
	客官可以在这里：
	    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
	    ＊	典当(pawn)		＊
	    ＊	卖断(sell)		＊
	    ＊	估价(value)		＊
	    ＊	赎回(retrieve stamp)	＊
	    ＊	清单(list)	        ＊
	    ＊	购买(buy id)            ＊
	    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
	各种货物，铜钱、银两、黄金、银票一概通用。
	"]));
	set("objects", ([
		__DIR__"npc/boss_tang" : 1,
	]));
	set("exits", ([
		"north" : __DIR__"road_laibin2",
	]));

	setup();
}
