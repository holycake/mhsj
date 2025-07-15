// Room: /d/wudang/lgfang
// by netkill 98-10-9 

inherit ROOM;

void create()
{
    set("short", "走廊");
    set("long", @LONG
一条干净的走廊，走廊两边被竹林所遮盖，看上去十分的舒服，不时
可以听到鸟儿唧唧喳喳的叫声。
LONG
    );

    set("exits", ([
	"west" : __DIR__"zuofang",
	"east"  :__DIR__"youfang",
	"north" : __DIR__"xiaolu1"
	]));
                             
       setup();
    replace_program(ROOM);
}

