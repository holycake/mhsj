// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;

void create()
{
    set("short", "左偏殿");
    set("long", @LONG
这是一间偏殿，殿内挂有历代道家名范的画像，地上有几个蒲团，几
个道童正在打坐入定，一片安定祥和的气氛。
LONG
    );

    set("exits", ([
	"north" : __DIR__"zoulang",
	"east"  :__DIR__"zijincheng"
	]));
             set("objects", ([
                "/d/wudang1/npc/daotong" : 2]));
                        
       setup();
    replace_program(ROOM);
}

