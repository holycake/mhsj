// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;

void create()
{
    set("short", "真武殿");
    set("long", @LONG
这里是真武殿。大殿的中间供放着一尊真武大帝的神像，端是威严肃
穆，案前香火疗绕，地上整齐地放着几个蒲团，左右两边分别通向一道走
廊，不时有进香客前来进香。
LONG
    );

    set("exits", ([
	"east" : __DIR__"zoulang1",
	"south"  :__DIR__"zijincheng",
	"west" : __DIR__"zoulang",
	]));
       set("objects", ([
		]));
                      
       setup();
    replace_program(ROOM);
}

