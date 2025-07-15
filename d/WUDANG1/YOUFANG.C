#include <ansi.h>
inherit ROOM;

void create()
{
    set("short",MAG "右厢房" NOR);
    set("long", @LONG
这是一间厢房，东边不时传来阵阵练武的声音，原来那边是练功房，
这里打扫的十分干净整洁。
LONG
    );

    set("exits", ([
	"east" : __DIR__"lgfang2",
	"south"  :__DIR__"zoulang1",
	"west" : __DIR__"zoulang2",
	]));
             set("objects", ([
               "/d/wudang1/npc/daiyan" : 1]));
       setup();

   replace_program(ROOM);
}


