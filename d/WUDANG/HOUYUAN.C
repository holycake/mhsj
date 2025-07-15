// houyuan.c 后院
//lpg 19991005

inherit ROOM;

void create()
{
        set("short", "后院");
        set("long", @LONG
这里是后院，北面是三清殿，南面是一个圆形的门洞，有一条小路通往
后山。
LONG );
        set("exits", ([
                "north" : __DIR__"sanqingdian",
        ]));
        setup();
        replace_program(ROOM);
}
