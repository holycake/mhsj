// tygate1.c 桃园篱笆
// by Marz 
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "榔梅园篱笆");
	set("long", @LONG
	你走在一条通往桃树林深处的小道上，前面有个篱笆门(fence)。
LONG
	);
	set("outdoors", "wudang");
	
	set("item_desc",([
		"fence"	:	"\n\t\t\t篱笆门上有首诗：\n\n\n" 
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　应　怜　屐　齿　印　苍　苔　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　小　扣　柴　扉　久　不　开　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　春　色　满　园　关　不　住　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　一　枝　红　杏　出　墙　来　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n\n\n",
							
		]));

	set("exits", ([
		"west" : __DIR__"langmei",
		"east" : __DIR__"nanyan",
	]));

         create_door("west", "竹门", "east", DOOR_CLOSED);

	setup();
       replace_program(ROOM);
}
