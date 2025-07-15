inherit ROOM;

void create()
{
        set("short", "古墓石林");
        set("long", @LONG
这是一片看似杂乱无章的石头阵，一走进来，你仿佛迷失了方向。
LONG
        );

        set("exits", ([
		"east" : __DIR__"sl1",
		"west" : __DIR__"sl",
		"south" : __DIR__"sl1",
		"north" : __DIR__"sl00",
        ]));
        setup();
        replace_program(ROOM);
}
