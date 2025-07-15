// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;

void create()
{
    set("short", "练功房");
    set("long", @LONG
这是一间练功房，依墙摆了几个木人，几名武当弟子正在和木人认真
的比划着，屋子很宽敞，坚硬的青石地板却被踩出了一道道裂缝，足见武
当弟子练功之刻苦。
LONG
    );

    set("exits", ([
	"west" : __DIR__"youfang",
	]));
    set("objects", ([
        __DIR__"npc/muren" : 3,
		]));                                                
       setup();
    replace_program(ROOM);
}

