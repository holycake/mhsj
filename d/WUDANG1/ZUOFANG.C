// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;


void create()
{
    set("short", "左厢房");
    set("long", @LONG
这是一间厢房，你不时可以看见一些睡眼朦胧的人进出，原来西面是
一间休息室，一道门(men)虚掩着。东边过去是一道走廊。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang2",
	"south"  :__DIR__"zoulang",
	"west"  :__DIR__"xiuxishi",
	]));
        
	
           
       setup();

   replace_program(ROOM);
}

