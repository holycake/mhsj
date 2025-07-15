// tygate2.c 桃园木门
// by Marz 

inherit ROOM;

void create()
{
	set("short", "桃园木门");
	set("long", @LONG
	你走在一条通往桃树林深处的小道上，前面有个桃木门(door)。
LONG
	);
	set("outdoors", "wudang");
	
	
	set("item_desc",([
		"door"	:	"\n\t\t\t桃木门上有首诗：\n\n\n" 
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　去　年　今　日　此　门　中　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　人　面　桃　花　相　映　红　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　人　面　不　知　何　处　去　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷　桃　花　依　旧　笑　春　风　∷∷∷\n"
					"\t\t∷∷∷　　　　　　　　　　　　　　　∷∷∷\n"
					"\t\t∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷∷\n\n\n",
							
		]));


	set("exits", ([
		"north" : __DIR__"tyroad10",
	]));

	setup();
}
