// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;

void create()
{
    set("short", "右偏殿");
    set("long", @LONG
这是一间偏殿，殿内挂有手书道德经全篇，地上有几个蒲团，几
个道童正在参详经书，你不由放轻了脚步。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang1",
	"west"  :__DIR__"zijincheng"
	]));
             set("objects", ([
               "/d/wudang1/npc/daotong" : 2]));
                        
       setup();
    replace_program(ROOM);
}

