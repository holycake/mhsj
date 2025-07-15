// xilang.c 西厢走廊
//lpg 19991005

inherit ROOM;

void create()
{
        set("short", "西厢走廊");
        set("long", @LONG
你走在一条走廊上，东边是大殿，北边是一座楼阁。西面楼上传来
阵阵打斗声。
LONG );
        set("exits", ([
//                "northup" : __DIR__"cangjingge",
                "east"    : __DIR__"sanqingdian",
//                "westup"  : __DIR__"caolianfang",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
