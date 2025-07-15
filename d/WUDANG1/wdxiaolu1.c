// Room: /d/wudang/wdxiaolu
// netkill /98/8/13/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",GRN "山脚" NOR);
        set("long", @LONG
小路来到这里已到了山脚，向南就是上山的路了，抬头看去，山路崎岖
看来上山还得花些力气。
LONG
        );
        set("exits", ([
  "north" : __DIR__"wdxiaolu",
  "southup" : __DIR__"houshan3",
]));

        set("no_clean_up", 0);
        set("outdoors", "wudang");

        setup();
        replace_program(ROOM);
}

