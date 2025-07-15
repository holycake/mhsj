// wdroad5.c
// netkill /98/8/17
inherit ROOM;

void create()
{
        set("short", "青石大道");
        set("long", @LONG
你走在一条青石大道上，四周静悄悄的。西北方向似乎有条黄土路。
LONG
        );
        set("outdoors", "wudang");

        set("exits", ([
                
                "northwest" : __DIR__"wdroad6",
                "south" : __DIR__"wdroad4",
        ]));

        setup();
        replace_program(ROOM);
}
