#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",MAG"紫" NOR+HIY"金"NOR+"殿" );
	set("long", @LONG
	在你的面前是一座道观，上面写着“紫金城”三个朱红色的大字，红砖
碧瓦，院墙上是一人般大小的“无量寿佛”四个大字。院中房间延绵百余间，身
穿不同服色的道士确不断进进出出，诵经的声音隐隐传来。再往北是一条竹林小道。
LONG
	);
       // set("outdoors", "wudang");

	set("exits", ([
		"south" : __DIR__"shilang",
 		"north" : __DIR__"zhendian",  
		"west"  : __DIR__"zuodian", //左偏殿
		"east"  : __DIR__"youdian", //右偏殿
	]));
             set("objects", ([
               "/d/wudang1/npc/lianzhou" : 1]));
 
	setup();
	//replace_program(ROOM);
}

